/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-13
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef tinhnop_local
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // tinhnop_local

#define ALL(v) (v).begin(), (v).end()

#if __cplusplus < 202002L
template <typename T> int ssize(const T &a) { return a.size(); }
#endif // __cplusplus

template <typename T1, typename T2>
bool maximize(T1 &a, T2 b) {
	return a < b ? a = b, true : false;
}

template <typename T1, typename T2>
bool minimize(T1 &a, T2 b) {
	return a > b ? a = b, true : false;
}

template<typename T>
struct Compressor {
	vector<T> h;

	void add(const T &x) {
		h.push_back(x);
	}

	void init() {
		sort(ALL(h));
		h.resize(unique(ALL(h)) - h.begin());
	}

	int get(const T &x) {
		return lower_bound(ALL(h), x) - h.begin() + 1;
	}
};
//} end of template

const int MAXN = 1e5 + 11;
const int INF = 1e9 + 11;

int n;
int64_t a[MAXN], b[MAXN], c[MAXN], hb[MAXN], hc[MAXN];
int st[4 * MAXN];

Compressor<int64_t> com;
map<int64_t, vector<pair<int, int> > > mp;

void update(int id, int l, int r, int pos, int val) {
	if (l > pos || pos > r) return ;
	if (l == r) {
		minimize(st[id], val);
		return ;
	}

	int mid = (l + r) >> 1;

	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);

	st[id] = min(st[id << 1], st[id << 1 | 1]);
}

int Get(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return INF;
	if (u <= l && r <= v) return st[id];

	int mid = (l + r) >> 1;

	return min(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#define task "A"
	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	//____________________________________
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		b[i] += b[i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		c[i] += c[i - 1];
	}

	com.add(0);

	for (int i = 1; i <= n; ++i) {
		hb[i] = a[i] - b[i];
		hc[i] = a[i] - c[i];
		com.add(hc[i]);
	}

	com.init();

	for (int i = 0; i <= n; ++i) {
		mp[hb[i]].emplace_back(com.get(hc[i]), i);
	}

	memset(st, 0x3f, sizeof(st));

	for (auto &x : mp) {
		sort(ALL(x.second));
		debug(x.second);
	}

	int ans = 0;

	for (auto &x : mp) {
		for (auto &c : x.second) {
			update(1, 1, n, c.first, c.second);
		}
		for (auto &c : x.second) {
			maximize(ans, c.second - Get(1, 1, n, 1, c.first));
		}
	}

	cout << ans;
}
