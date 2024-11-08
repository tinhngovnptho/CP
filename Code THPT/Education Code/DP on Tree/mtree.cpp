/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 11; 
const int MOD = 1e9 + 7;

int n;
vector <pair<int, int> > adj[MAXN];
int dp1[MAXN], dp2[MAXN];

void add(int &a, int b) {
	a += b; 
	if (a >= MOD) a -= MOD;
}

void mul(int &a, int b) {
	int64_t res = 1ll * a * b; 
	a = res % MOD;
}

int ans = 0;

void dfs(int u, int parent = 0) {
	for (auto &x : adj[u]) {
		int v = x.first;
		int w = x.second;
		if (v == parent) continue;
		add(dp1[v], 1ll * w * (dp1[u] + 1) % MOD);
		dfs(v, u);
		int res = 1ll * w * (dp2[v] + 1) % MOD;
		add(ans, 1ll * dp2[u] * res % MOD);
		add(dp2[u], res);
	}
}

void run_case(void) {
	cin >> n; 
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w; 
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}	
	dfs(1);
	for (int i = 1; i <= n; ++i) add(ans, dp1[i]);
	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("mtree.inp", "r", stdin);
	freopen("mtree.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
