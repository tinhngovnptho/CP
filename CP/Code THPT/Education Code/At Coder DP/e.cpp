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

const int MAX = 1e5 + 11, MAXN = 111;

int n, W;
int64_t v[MAXN], w[MAXN], dp[MAX];

void minimize(int64_t &a, int64_t b) {
	if (a > b) a = b;
}

void tinhnop() {
	cin >> n >> W;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i] >> v[i];
	}
	int sum = accumulate(v + 1, v + n + 1, 0);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = sum - v[i]; ~j; --j) {
			if (dp[j] + w[i] <= W) minimize(dp[j + v[i]], dp[j] + w[i]);
		}
	}
	for (int i = sum; ~i; --i) if (dp[i] <= W) {
		cout << i;
		return ;
	}
}
///////////////////////////////////////////
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("e.inp", "r", stdin);
	freopen("e.out", "w", stdout);
///////////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
	return 0;
}
