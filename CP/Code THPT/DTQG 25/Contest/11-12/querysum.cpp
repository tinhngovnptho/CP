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

#define TASK "querysum"

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

int64_t st[4 * maxN];

void update(int id, int l, int r, int pos, int val) {
	if (l > pos || pos > r) return ;
	if (l == r) {
		st[id] = val;
		return ;
	}

	int mid = (l + r) >> 1;

	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);

	st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int64_t query(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) {
		return st[id];
	}

	int mid = (l + r) >> 1;

	return max(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(false);
	setIO();
	cin >> n >> q;
	while (q--) {
		char op;
		int i, j;
		cin >> op >> i >> j;

		if (op == 'S') {
			update(1, 1, n, i, j);
		} else if (op == 'Q') {
			cout << query(1, 1, n, i, j) << '\n';
		}
	}
}

