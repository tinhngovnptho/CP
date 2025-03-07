/*
	Author: tinhnopro
	created: 19.01.2025 16:50:13
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "aqueen"

using namespace std;

using i64 = long long;


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	i64 n, m; 
	cin >> n >> m; 

	i64 x = n / 2 + (n & 1LL);
	i64 y = m / 2 + (m & 1LL);

	// cout << x << ' ' << y << '\n';
	i64 ans = n + m - 2; 

	ans += min(x - 1, y - 1) + min(n - x, m - y);
	ans += min(x - 1, m - y) + min(y - 1, n - x);

	cout << ans; 
}