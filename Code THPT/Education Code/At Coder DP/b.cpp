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

void minimize(int &a, int b) {
	if (a > b) a = b;
}

void tinhnop() {
	const int inf = 1e9 + 11;
	int n, k; cin >> n >> k;
	vector<int> a(n + 2), dp(n + 2, inf);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dp[1] = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) if (i - j >= 1) {
			minimize(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
		}
	}
	cout << dp[n];
}
///////////////////////////////////////////
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("b.inp", "r", stdin);
	freopen("b.out", "w", stdout);
///////////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
	return 0;
}
