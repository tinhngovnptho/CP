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

const int maxN = 411;

int n, a[maxN];
int64 dp[maxN][maxN], sum[maxN];

void minimize(int64 &a, int64 b) {
	if (a > b) a = b;
}

void tinhnop() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];

	memset(dp, 0x3f, sizeof(dp));

	for (int i = 1; i <= n; ++i) dp[i][i] = 0;

	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i <= n - len + 1; ++i) {
			int j = i + len - 1;
			for (int k = i; k < j; ++k) {
				minimize(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
			}
		}
	}
	cout << dp[1][n];
}
////////////////////////////////////////
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("n.inp", "r", stdin);
	freopen("n.out", "w", stdout);
///////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
