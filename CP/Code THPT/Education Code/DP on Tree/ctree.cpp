/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 11; 

int n;
vector <int> adj[MAXN];
int dp[MAXN][2];

void dfs(int u, int parent = -1) {
	dp[u][0] = 1; 
	dp[u][1] = 2; 
	for (int &v : adj[u]) if (v != parent) {
		dfs(v, u);
		dp[u][0] += dp[v][1];
		dp[u][1] += dp[v][0];
	}
}

void run_case(void) {
	cin >> n; 
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("ctree.inp", "r", stdin);
	freopen("ctree.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
