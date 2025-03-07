/*
	Author: tinhnopro
	created: 26.02.2025 15:57:30
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "trip"

using namespace std;

using i64 = long long;

int n, a[25][25]; 
i64 dp[25][1 << 21], trace[25][1 << 21];

constexpr int onbit(const int& mask, const int& pos) {
	return mask | (1 << pos);
}

int start;
vector<int> cycle; 

i64 calc(int i, int mask) {
	if (mask == (1 << n) - 1) return a[i][start]; 
	if (~dp[i][mask]) return dp[i][mask]; 

	i64 cur = (i64)1e18 + 11; 

	for (int j = 1; j <= n; ++j) {
		if ((mask >> (j - 1)) & 1) continue;
		cur = min(cur, calc(j, onbit(mask, j - 1)) + a[i][j]);
	}
	
	return dp[i][mask] = cur; 
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j]; 
		}
	}

	memset(dp, -1, sizeof(dp));

	start = 1; 
	i64 d = calc(start, 1 << (start - 1));

	cout << d; 
}