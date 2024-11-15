/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-13
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


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	file("I");
//__________________________________
	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1), b(m + 1);
	vector<vector<int> > dp;
	dp.assign(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (a[i] == b[j]) {
			dp[i][j] = 1;
			for (int k = 1; k < i; ++k) {
				for (int t = 1; t < j; ++t) if (a[k] == b[t] && a[k] < a[i]) {
					maximize(dp[i][j], dp[k][t] + 1);
				}
			}
			maximize(ans, dp[i][j]);
		}
	}

	cout << ans;
}
