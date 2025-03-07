/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-09
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;
const int LOG = 17;

int n, q;
vector<int> adj[maxN];
int depth[maxN], up[LOG + 1][maxN], f[maxN];
int cnt = 0;

void dfs(int u, int parent) {
	for (int v : adj[u]) if (v ^ parent) {
		depth[v] = depth[u] + 1;
		up[0][v] = u;

		for (int i = 1; i <= LOG; ++i)
			up[i][v] = up[i - 1][up[i - 1][v]];

		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (u == v) return u;

	if (depth[u] < depth[v]) swap(u, v);

	int d = depth[u] - depth[v];

	for (int i = 0; (1 << i) <= d; ++i)
		if ((d >> i) & 1) u = up[i][u];

	if (u == v) return u;

	for (int i = LOG; ~i; --i) if (up[i][u] != up[i][v]) {
		u = up[i][u];
		v = up[i][v];
	}

	return up[0][u];
}

void dfs2(int u, int parent) {
	for (int v : adj[u]) if (v ^ parent) {
		dfs2(v, u);
		f[u] += f[v];
	}
	if (u != 1 && f[u] == 0) cnt++;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen("d.inp", "r")) {
		freopen("d.inp", "r", stdin);
		freopen("d.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	up[0][1] = 1;
	dfs(1, 1);

	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		f[u]++;
		f[v]++;
		f[lca(u, v)]-= 2;
	}

	dfs2(1, 1);

	cout << cnt;
}

