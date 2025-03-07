/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-08
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4 + 5, mod = 2021;

int n, m, c[maxN];
vector<int> adj[maxN];
int mask, dp[maxN], sum;

void add(int& a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void sub(int& a, int b) {
	a -= b;
	if (a < 0) a += mod;
	if (a >= mod) a -= mod;
}

void dfs(int u, int parent) {
	if ((mask >> c[u]) & 1) dp[u] = 0;
	else dp[u] = 1;

	for (int v : adj[u]) if (v ^ parent) {
		dfs(v, u);

		dp[u] = 1LL * dp[u] * (dp[v] + 1) % mod;
	}
	add(sum, dp[u]);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen("c.inp", "r")) {
		freopen("c.inp", "r", stdin);
		freopen("c.out", "w", stdout);
	}

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		c[i]--;
	}

	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int res = 0;

	for (mask = 0; mask < (1 << m); ++mask) {
		sum = 0;
		dfs(1, 1);
		if (__builtin_popcount(mask) & 1) sub(res, sum);
		else add(res, sum);
	}

	cout << res;
}

