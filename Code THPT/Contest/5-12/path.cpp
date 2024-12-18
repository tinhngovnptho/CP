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

struct Node {
	int v, w;
	Node() : v(0), w(0) {}
	Node(int _v, int _w) : v(_v), w(_w) {}
};

int n, q;
vector<Node> adj[maxN];
int depth[maxN], par[LOG + 1][maxN], minW[LOG + 1][maxN], maxW[LOG + 1][maxN];

void dfs(int u, int parent) {
	for (Node x : adj[u]) {
		int v = x.v;
		int w = x.w;
		if (v == parent) continue;

		depth[v] = depth[u] + 1;

		minW[0][v] = w;
		maxW[0][v] = w;
		par[0][v] = u;

		for (int i = 1; i <= LOG; ++i) {
			par[i][v] = par[i - 1][par[i - 1][v]];
			minW[i][v] = min(minW[i - 1][v], minW[i - 1][par[i - 1][v]]);
			maxW[i][v] = max(maxW[i - 1][v], maxW[i - 1][par[i - 1][v]]);
		}

		dfs(v, u);
	}
}

int getmax(int u, int v) {
	if (u == v) return 0;
	int ret = 0;
	if (depth[u] < depth[v]) swap(u, v);

	int len = depth[u] - depth[v];

	for (int i = 0; i <= LOG; ++i) if ((len >> i) & 1) {
		ret = max(ret, maxW[i][u]);
		u = par[i][u];
	}

	if (u == v) return ret;

	for (int i = LOG; ~i; --i) if (par[i][u] != par[i][v]) {
		ret = max(ret, maxW[i][u]);
		ret = max(ret, maxW[i][v]);
		u = par[i][u];
		v = par[i][v];
	}

	ret = max(ret, maxW[0][u]);
	ret = max(ret, maxW[0][v]);

	return ret;
}

int getmin(int u, int v) {
	if (u == v) return 0;
	int ret = 1e9;
	if (depth[u] < depth[v]) swap(u, v);

	int len = depth[u] - depth[v];

	for (int i = 0; i <= LOG; ++i) if ((len >> i) & 1) {
		ret = min(ret, minW[i][u]);
		u = par[i][u];
	}

	if (u == v) return ret;

	for (int i = LOG; ~i; --i) if (par[i][u] != par[i][v]) {
		ret = min(ret, minW[i][u]);
		ret = min(ret, minW[i][v]);
		u = par[i][u];
		v = par[i][v];
	}

	ret = min(ret, minW[0][u]);
	ret = min(ret, minW[0][v]);

	return ret;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(false);
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	par[0][1] = 1;
	minW[0][1] = 1e9;
	maxW[0][1] = -1;

	dfs(1, 1);

	cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;

		cout << getmin(u, v) << ' ' << getmax(u, v) << '\n';
	}
}

