/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 11; 
const int MOD = 1e9 + 7;

int n; 
vector <int> adj[MAXN];
int dp[MAXN][2];

void mul(int &a, int b) {
	int64_t ret = 1ll * a * b;
	a = ret % MOD;  
}

void dfs_dp(int u, int parent = -1) {
	dp[u][0] = 1; dp[u][1] = 1; 
	for (int &v : adj[u]) if (v != parent) {
		dfs_dp(v, u);
		mul(dp[u][0], dp[v][1]);
		mul(dp[u][1], (dp[v][1] + dp[v][0]) % MOD);
	}
}

void run_case(void) {
	cin >> n; 
	for (int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	dfs_dp(1);
	cout << (dp[1][0] + dp[1][1]) % MOD; 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("atcoder_dp_p.inp", "r", stdin);
	freopen("atcoder_dp_p.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
