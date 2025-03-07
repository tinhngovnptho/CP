/*
	Author: tinhnopro
	created: 06.03.2025 09:34:34
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "at3"

using namespace std;

using i64 = long long;

int n, q; 
const int maxN = 8e4 + 5;
const i64 INF = (i64) 1e18 + 11;

i64 st[4 * maxN], lazy[4 * maxN]; 

void down(int id,int l,int r) {
	if (!lazy[id]) return ;
	int mid = (l + r) >> 1;

	if (l != r) {
		st[id << 1] = 1LL * (mid - l + 1) * lazy[id];
		st[id << 1 | 1] = 1LL * (r - mid) * lazy[id]; 

		lazy[id << 1] = lazy[id]; 
		lazy[id << 1 | 1] = lazy[id]; 
	}

	lazy[id] = 0; 
}

void update(int id, int l, int r, int u, int v, i64 val) {
	if (l > v || r < u) return ;  

	if (u <= l && r <= v) {
		st[id] = 1LL * val * (r - l + 1); 
		lazy[id] = val; 
		return ; 
	}

	int mid = (l + r) >> 1; 

	down(id, l, r);

	update(id << 1, l, mid, u, v, val); 
	update(id << 1 | 1, mid + 1, r, u, v, val); 

	st[id] = st[id << 1] + st[id << 1 | 1];
}

i64 query(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return 0; 
	if (u <= l && r <= v) {
		// cerr << st[id] << ' ';
		return st[id]; 
	}

	down(id, l, r); 

	int mid = (l + r) >> 1; 

	return query(id << 1, l, mid, u, v) + query(id << 1 | 1, mid + 1, r, u, v);
}

int getPos(int mx, int p) {
	int Left = 1, Right = mx, res = mx + 1; 
	i64 sum;
	int mid;  

	while (Left <= Right) {
		mid = (Left + Right) >> 1; 

		sum = query(1, 0, n, mid, mx); 
		if ((p + sum) / (mx - mid + 1) + ((p + sum) % (mx - mid + 1) > 0) > query(1, 0, n, mid - 1, mid - 1)) {
			res = mid; 
			Right = mid - 1; 
		} else {
			Left = mid + 1; 
		}
	}

	return res - 1; 
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> q; 

	update(1, 0, n, 0, 0, INF);

	int r, p;

	while(q--) {
		cin >> r >> p; 
		
		int first_pos = getPos(r, p); 

		i64 sum = query(1, 0, n, first_pos, r); 

		i64 val = (p + sum) / (r - first_pos + 1);

		// cout << first_pos << ' ' << val << '\n';

		update(1, 0, n, first_pos, r, val); 

		int idx = (p + sum) % (r - first_pos + 1); 

		update(1, 0, n, first_pos, first_pos + idx - 1, val + 1);

		// for (int i = 1; i <= n; ++i) cout << query(1, 0, n, i, i) << ' '; 
		// cout << '\n';
	}

	for (int i = 1; i <= n; ++i) cout << query(1, 0, n, i, i) << ' '; 
}