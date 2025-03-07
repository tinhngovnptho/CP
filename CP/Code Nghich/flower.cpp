/*
	Author: tinhnopro
	created: 21.02.2025 21:41:36
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "flower"

using namespace std;

using i64 = long long;

struct Compressor {
	vector<int> v; 

	void add(const int& x) {
		v.push_back(x);
	}

	void Compress() {
		sort(v.begin(), v.end()); 
		v.resize(unique(v.begin(), v.end()) - v.begin());
	}

	int Get(const int& x) {
		return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; 
	}
};

const int maxN = 1e5 + 5, INF = 1e9 + 11; 

int n, m; 

int a[maxN], l[maxN], r[maxN], v[maxN];

Compressor com; 

pair<int, int> seg[4 * maxN]; 

void update(int id, int l, int r, int pos, int val) {
	if (l > pos || pos > r) return ; 
	if (l == r) {
		seg[id].first = seg[id].second = val; 
		return ;
	}

	int mid = (l + r) >> 1; 
	
	update(id << 1, l, mid, pos, val); 
	update(id << 1 | 1, mid + 1, r, pos, val);

	seg[id].first = max(seg[id << 1].first, seg[id << 1 | 1].first); 
	seg[id].second = min(seg[id << 1].second, seg[id << 1 | 1].second);
}

pair<int, int> query(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return {-INF, INF}; 
	if (u <= l && r <= v) return seg[id]; 

	int mid = (l + r) >> 1; 

	pair<int, int> Left = query(id << 1, l, mid, u, v); 
	pair<int, int> Right = query(id << 1 | 1, mid + 1, r, u, v); 
	return {max(Left.first, Right.first), min(Left.second, Right.second)};
}

int walk(int id, int l, int r, int idx, int L, int R) {
	if (r < idx) return -1; 
	// cout << l << ' ' << r << ' ' << id << '\n';
	if (l == r) {
		// cout << seg[id].first << ' ' << seg[id].second << '\n';
		return l; 
	}

	int mid = (l + r) >> 1; 

	if (seg[id << 1].first >= L && seg[id<< 1].second <= R) {
		int res = 0;
		res = walk(id << 1, l, mid, idx, L, R);
		if (res > 0) return res; 
	}

	if (seg[id << 1 | 1].first >= L && seg[id << 1 | 1].second <= R) {
		int res = 0;
		res = walk(id << 1 | 1, mid + 1, r, idx, L, R);
		if (res > 0) return res; 
	}

	return -1; 
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> m; 
	
	vector<int> p(n); 
	
	iota(p.begin(), p.end(), 1);

	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= m; ++i) {
		cin >> v[i] >> l[i] >> r[i]; 
	}

	sort(p.begin(), p.end(), [](const int &i, const int &j){
		if (a[i] != a[j]) return a[i] < a[j];
		else return i < j; 
	});
	
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; ++i) {
		update(1, 1, n, i, p[i - 1]);
	}

	for (int i = 1; i <= m; ++i) {
		int idx = lower_bound(a + 1, a + n + 1, v[i]) - a;

		int idx2 = walk(1, 1, n, idx, l[i], r[i]); 

		if (idx2 > 0) {
			cout << p[idx2 - 1] << '\n'; 
			update(1, 1, n, idx2, -1);
		} else {
			cout << -1 << '\n'; 
		}
	}
}