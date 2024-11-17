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

const int MAXN = 1e5 + 11;

int a[3][MAXN], dp[3][MAXN];
int n;

void maximize(int &a, int b) {
	if (a < b) a = b;
}

void tinhnop() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) cin >> a[j][i];
	}

	for (int j = 0; j < 3; ++j) dp[j][1] = a[j][1];

	for (int i = 2; i <= n; ++i) {
		dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[0][i];
		dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + a[1][i];
		dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + a[2][i];
	}

	int ans = 0;
	for (int j = 0; j < 3; ++j) maximize(ans, dp[j][n]);
	cout << ans;
}
///////////////////////////////////////////
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("c.inp", "r", stdin);
	freopen("c.out", "w", stdout);
///////////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
	return 0;
}
