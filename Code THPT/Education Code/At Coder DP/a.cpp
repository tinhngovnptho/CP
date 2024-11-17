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

const int MAXN = 1e6 + 11;

int n, a[MAXN], dp[MAXN];

void tinhnop() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = dp[1] = 0;
	dp[2] = abs(a[1] - a[2]);
	for (int i = 3; i <= n; ++i) {
		dp[i] = min(dp[i - 1] + abs(a[i - 1] - a[i]), dp[i - 2] + abs(a[i - 2] - a[i]));
	}
	cout << dp[n];
}
///////////////////////////////////////////
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("a.inp", "r", stdin);
	freopen("a.out", "w", stdout);
///////////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
	return 0;
}
