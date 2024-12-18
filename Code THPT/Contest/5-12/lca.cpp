/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-05
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define TASK "path"

using namespace std;

const int maxN = 1e5 + 5, LOG = 17;

int n, q;
vector<int> adj[maxN];
int depth[maxN], st[LOG + 1][maxN];

void dfs(int u, int parent) {
	st[0][u] = parent;
	for (int i = 1; i <= LOG; ++i) st[i][u] = st[i - 1][st[i - 1][u]];

	for (int v : adj[u]) if (v ^ parent) {
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (u == v) return u;
	if (depth[u] < depth[v]) swap(u, v);
	for (int i = LOG; ~i; --i) if (depth[st[i][u]] >= depth[v]) {
		u = st[i][u];
	}
	if (u == v) return u;

	for (int i = LOG; ~i; --i) if (st[i][u] != st[i][v]) {
		u = st[i][u];
		v = st[i][v];
	}

	return st[0][u];
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(false);
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);

	cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}

