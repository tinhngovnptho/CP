/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-15
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef tinhnop_local
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // tinhnop_local

#define ALL(v) (v).begin(), (v).end()
#define ssize(s) ((signed) (s).size())

const int MAXN = 111, MAX = 1e5 + 11;

int n, W;
int64_t v[MAXN], w[MAXN], dp[MAXN][MAX];

void maximize(int64_t &a, int64_t b) {
	if (a < b) a = b;
}

void tinhnop() {
	cin >> n >> W;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= W; ++j) {
			if (j >= w[i]) maximize(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			maximize(dp[i][j], dp[i - 1][j]);
		}
	}

	cout << dp[n][W];
}
///////////////////////////////////////////
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("d.inp", "r", stdin);
	freopen("d.out", "w", stdout);
///////////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
	return 0;
}
