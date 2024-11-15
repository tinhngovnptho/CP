/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-14
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#define ALL(v) (v).begin(), (v).end()
#define ssize(s) (int) (s).size()

#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template <typename A, typename B> bool minimize(A &a, B b)  { return a > b ? a = b, true : false; }
template <typename A, typename B> bool maximize(A &a, B b)  { return a < b ? a = b, true : false; }
//} end of template

const int MAXN = 3011;

int n;
double a[MAXN], dp[MAXN][MAXN];


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
	freopen("i.inp", "r", stdin);
	freopen("i.out", "w", stdout);
#endif // LOCAL
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int can =  n / 2 + 1;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= can; ++j) {
			dp[i][j] = dp[i - 1][j - 1] * a[i] + dp[i - 1][j] * (1 - a[i]);
		}
	}

	cout << fixed << setprecision(10) << dp[n][can];
}
