/*
	Author: tinhnopro
	created: 19.01.2025 22:52:49
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "dbeauty"

using namespace std;

using i64 = long long;

const int maxN = 4e5 + 5; 

int n, x; 
i64 dp[maxN], a[maxN]; 

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> x; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}

	i64 res = 0; 

	for (int i = 1; i <= n; ++i) {
		dp[0] = max(0LL, dp[0] + a[i]);
		dp[1] = max(dp[0], dp[1] + 1LL * a[i] * x); 
		dp[2] = max(dp[1], dp[2] + a[i]); 

		res = max(res, dp[2]); 
	}

	cout << res; 
}