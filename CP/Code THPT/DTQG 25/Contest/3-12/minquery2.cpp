/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-03
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define TASK ""

using namespace std;

template <typename T> int isize(const T& a) { return a.size(); }

bool maximize(int& a, int b) {
	return a < b ? a = b, true : false;
}

bool minimize(int& a, int b) {
	return a > b ? a = b, true : false;
}

const int maxN = 1e5 + 11, LOG = 17;

int n, m, q, a[maxN], st[LOG + 1][maxN];

int Get(int i, int j) {
	return (i - 1) * m + j;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (ifstream(TASK ".inp")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[Get(i, j)];
		}
	}

	int sz = n * m;

	for (int i = 1; i <= sz; ++i) st[0][i] = a[i];

	for (int j = 1; j <= LOG; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= sz; ++i) {
			st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
		}
	}

	auto query = [&] (int l, int r) -> int {
		int k = __lg(r - l + 1);
		return min(st[k][l], st[k][r - (1 << k) + 1]);
	};

	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		cout << query(Get(l1, r1), Get(l2, r2)) << '\n';
	}
}

