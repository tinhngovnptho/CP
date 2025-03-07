/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;

int n, p;
int c[MAXN];
vector <int> adj[MAXN];
int dp[MAXN][MAXN], trace[MAXN][MAXN], sz[MAXN], par[MAXN];

bool maximize(int &a, int b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void dfs(int u, int parent = -1) {
	sz[u] = 1;
	par[u] = parent;
	for (int i = 0; i <= p; ++i) dp[u][i] = (int)-1000000009;
	dp[u][1] = c[u];
	for (int &v : adj[u]) if (v != parent) {
		dfs(v, u);
		for (int cntu = sz[u]; cntu >= 0; --cntu)
			for (int cntv = 0; (cntu + cntv <= p && cntv <= sz[v]); ++cntv)
				if (dp[u][cntu + cntv] < dp[u][cntu] + dp[v][cntv]) {
					dp[u][cntu + cntv] = dp[u][cntu] + dp[v][cntv];
					trace[v][cntu + cntv] = cntv;
				}
		sz[u] += sz[v];
	}
}

void Trace(int u, int cnt) {
	for (int i = adj[u].size() - 1; i >= 0; --i) {
		int v = adj[u][i];
		if (v == par[u]) continue;
		if (trace[v][cnt]) {
			Trace(v, trace[v][cnt]);
			cnt -= trace[v][cnt];
		}
	}
	cout << u << " ";
}

void run_case(void) {
	cin >> n >> p;

	for (int i = 1; i <= n; ++i) cin >> c[i];

	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	int best = 1;
	for (int i = 2; i <= n; ++i) if (dp[i][p] > dp[best][p]) best = i;
	Trace(best, p);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("ptree.inp", "r", stdin);
	freopen("ptree.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
