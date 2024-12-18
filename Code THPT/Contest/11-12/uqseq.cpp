/**
 * Author: tinhnopro (tinh nop)
 * Created: 2024-12-11
 */
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define TASK "uqseq"

using namespace std;

//mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline void setIO() {
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}
}

const int maxN = 1e5 + 5;

int n, q;
int st[4 * maxN], lazy[4 * maxN];

void down(const int& id) {
	if (lazy[id]) {
		st[id << 1] += lazy[id];
		st[id << 1 | 1] += lazy[id];
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
		lazy[id] = 0;
	}
}

void update(int id, int l, int r, int u, int v, int val) {
	if (l > v || r < u) return ;
	if (u <= l && r <= v) {
		st[id] += val;
		lazy[id] += val;
		return ;
	}

	down(id);
	int mid = (l + r) >> 1;

	update(id << 1, l, mid, u, v, val);
	update(id << 1 | 1, mid + 1, r, u, v, val);

	st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int query(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return -1e9;
	if (u <= l && r <= v) return st[id];

	down(id);
	int mid = (l + r) >> 1;

	return max(query(id << 1, l, mid, u, v),
						query(id << 1 | 1, mid + 1, r, u, v));
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(false);
	setIO();
	cin >> n >> q;
	while (q--) {
		char op;
		cin >> op;

		if (op == 'Q') {
			int i; cin >> i;
			cout << query(1, 1, n, i, i) << '\n';
		} else {
			int i, j, delta;
			cin >> i >> j >> delta;
			update(1, 1, n, i, j, delta);
		}
	}
}

