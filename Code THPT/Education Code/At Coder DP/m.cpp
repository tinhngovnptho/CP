/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-16
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#define ssz(s) ((int) (s).size())
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;
typedef unsigned long long uint64;
////////////////////////////////////////

const int mod = 1e9 + 7, maxN = 111, maxV = 1e5 + 5;
int n, k, a[maxN], dp[maxN][maxV], sum[maxN][maxV];

void add(int &a, int b) {
	 a += b;
	 if (a >= mod) a -= mod;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

void tinhnop() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int j = 0; j <= a[1]; ++j) {
		dp[1][j] = 1;
	}

	sum[1][0] = 1;

	for (int j = 1; j <= k; ++j) {
		sum[1][j] = sum[1][j - 1];
		add(sum[1][j], dp[1][j]);
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			add(dp[i][j], sub(sum[i - 1][j], (j > a[i] ? sum[i - 1][j - a[i] - 1] : 0)));
			if (j > 0) sum[i][j] = sum[i][j - 1];
			add(sum[i][j], dp[i][j]);
//			debug(i, j, dp[i][j], sum[i][j]);
		}
	}
	cout << dp[n][k];
}
////////////////////////////////////////
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("m.inp", "r", stdin);
	freopen("m.out", "w", stdout);
///////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
