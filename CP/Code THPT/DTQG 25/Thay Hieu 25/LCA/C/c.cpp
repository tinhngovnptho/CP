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

const int maxN = 1e5 + 5, LOG = 17;
const int inf = 1e9 + 11;

struct Node {
	int v, w;
	Node() : v(0), w(0) {}
	Node(int _v, int _w) : v(_v), w(_w) {}
};

struct edge_t {
	int u, v, w;
	edge_t() : u(0), v(0), w(0) {}
	edge_t(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

struct DSU {
	int lab[maxN];

	DSU() {
		memset(lab, -1, sizeof(lab));
	}

	int find_par(int u) {
		return lab[u] < 0 ? u : lab[u] = find_par(lab[u]);
	}

	bool join(int u, int v) {
		u = find_par(u);
		v = find_par(v);

		if (u == v) return false;

		if (lab[u] > lab[v]) swap(u, v);

		lab[u] += lab[v];
		lab[v] = u;

		return true;
	}
} dsu;

int n, m;
vector<Node> adj[maxN], tree[maxN];
vector<edge_t> edges;
int depth[maxN], up[LOG + 1][maxN], mi[LOG + 1][maxN];

void dfs(int u, int parent) {
	for (Node x : tree[u]) {
		int v = x.v;
		int w = x.w;

		if (v == parent) continue;

		mi[0][v] = w;
		up[0][v] = u;
		depth[v] = depth[u] + 1;

		for (int i = 1; i <= LOG; ++i) {
			up[i][v] = up[i - 1][up[i - 1][v]];
			mi[i][v] = min(mi[i - 1][v], mi[i - 1][up[i - 1][v]]);
		}

		dfs(v, u);
	}
}

int getmin(int u, int v) {
	if (u == v) return 0;
	if (depth[u] < depth[v]) swap(u, v);

	int d = depth[u] - depth[v];
	int res = inf;

	for (int i = 0; (1 << i) <= d; ++i) if ((d >> i) & 1) {
		res = min(res, mi[i][u]);
		u = up[i][u];
	}

	if (u == v) return res;

	for (int i = LOG; ~i; --i) if (up[i][u] != up[i][v]) {
		res = min(res, min(mi[i][u], mi[i][v]));
		u = up[i][u];
		v = up[i][v];
	}

	res = min(res, min(mi[0][u], mi[0][v]));

	return res;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (fopen("c.inp", "r")) {
		freopen("c.inp", "r", stdin);
		freopen("c.out", "w", stdout);
	}

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges.emplace_back(u, v, w);
	}

	sort(edges.begin(), edges.end(), [&](const edge_t& a, const edge_t& b) {
		return a.w > b.w;
	});

	for (edge_t e : edges) {
		if (!dsu.join(e.u, e.v)) continue;
		tree[e.u].emplace_back(e.v, e.w);
		tree[e.v].emplace_back(e.u, e.w);
	}

	up[0][1] = 1;
	mi[0][1] = inf;
	dfs(1, 1);

	int64_t tot = 0;

	for (edge_t e : edges) {
		tot += getmin(e.u, e.v) - e.w;
	}

	cout << tot;
}

