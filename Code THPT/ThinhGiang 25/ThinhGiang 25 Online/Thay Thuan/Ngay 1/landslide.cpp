/*
	Author: Tinhnopro (Tinh nop)
	From: CHV Phu Tho
 */
#include<bits/stdc++.h> 

namespace std {
	// optimize min max
	template<typename T1, typename T2> bool maximize(T1 &a, T2 b) { return a < b ? a = b, 1 : 0; }
	template<typename T1, typename T2> bool minimize(T1 &a, T2 b) { return a > b ? a = b, 1 : 0; }
	// vector
	template<typename T, int D> struct vec : public vector<vec<T, D - 1>> {
		static_assert(D >= 1, "Init error");
		template<typename... Args>
			vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
	};
	template<typename T> struct vec<T, 1> : public vector<T> {
		vec(int n = 0, T val = T()) : vector<T>(n, val) {}
		template<typename InputIt>
			vec(InputIt first, InputIt last) : vector<T>(first, last) {}
	};
	// size
	template<typename T> int Size(const T &a) {  return a.size(); }
}
using namespace std;

struct Node {
	int v, w; 
	Node() {
		v = w = 0;
	}
	Node(int _v, int _w) {
		v = _v;
		w = _w;
	}
};

struct Edge {
	int u, v, w; 
	Edge() {
		u = v = w = 0;
	}

	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

const int MAXN = 2e5 + 11; 
const int64_t INF = 1e18 + 11; 

int n, s, q, h;

int c[MAXN];

vector <Node> adj[MAXN];
vector <Edge> edges; 

int timeIn[MAXN], timeOut[MAXN], par[MAXN], depth[MAXN], sz[MAXN], arr[MAXN];

int chainHead[MAXN], chainID[MAXN], pos[MAXN];
int64_t w[MAXN], dp[MAXN];

struct Segtree {
	int64_t st[4 * MAXN];

	Segtree() {
		memset(st, 0, sizeof(st));
	}

	void build(int id, int l, int r) {
		if (l == r) {
			st[id] = w[arr[l]] - dp[arr[l]];
			return ;
		}
		int mid = (l + r) >> 1; 
		build(id << 1, l, mid);
		build(id << 1 | 1, mid + 1, r);
		st[id] = max(st[id << 1], st[id << 1 | 1]);
	}

	int64_t Get(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return -INF;
		if (u <= l && r <= v) return st[id];
		int mid = (l + r) >> 1;
		return max(Get(id << 1, l, mid, u, v), 
					Get(id << 1 | 1, mid + 1, r, u, v));
	}
} it;

void dfs(int u, int parent = -1) {
	static int timeDFS = 0;
	timeIn[u] = ++timeDFS;
	dp[u] = INF;
	sz[u] = 1; 
	if (c[u]) dp[u] = 0;
	for (Node &x : adj[u]) if (x.v != parent) {
		par[x.v] = u;
		w[x.v] = w[u] + x.w;
		depth[x.v] = depth[u] + 1;
		dfs(x.v, u);
		sz[u] += sz[x.v];
		if (dp[x.v] != INF) minimize(dp[u], dp[x.v] + x.w);
	} 
	timeOut[u] = timeDFS;
}

int curChain = 1, curPos = 1; 

void HLD(int u, int parent = -1) {
	if (!chainHead[curChain]) {
		chainHead[curChain] = u;
	}
	chainID[u] = curChain;
	pos[u] = curPos;
	arr[curPos] = u;
	curPos++;

	int nxt = 0;
	
	for (Node &x : adj[u]) if (x.v != parent) {
		if (nxt == 0 || sz[x.v] > sz[nxt]) {
			nxt = x.v;
		}
	}

	if (nxt) HLD(nxt, u);

	for (Node &x : adj[u]) if (x.v != parent && x.v != nxt) {
		curChain++;
		HLD(x.v, u);
	}
}

int LCA(int u, int v) {
	while (chainID[u] != chainID[v]) {
		if (chainID[u] > chainID[v]) {
			u = par[chainHead[chainID[u]]];
		} else {
			v = par[chainHead[chainID[v]]];
		}
	}

	if (depth[u] > depth[v]) return v;
	return u;
}

int64_t Query(int u, int v) {
	int lca = LCA(u, v);
	int64_t res = -INF;
	while (chainID[u] != chainID[lca]) {
		int head = chainHead[chainID[u]];
		maximize(res, it.Get(1, 1, n, pos[head], pos[u]));
		u = par[head];
	}

	while (chainID[v] != chainID[lca]) {
		int head = chainHead[chainID[v]];
		maximize(res, it.Get(1, 1, n, pos[head], pos[v]));
		v = par[head];
	}

	if (depth[u] > depth[v]) swap(u, v);
	maximize(res, it.Get(1, 1, n, pos[u], pos[v]));

	return res; 
}

bool is_ancestor(int u, int v) {
	return timeIn[u] <= timeIn[v] && timeOut[v] <= timeOut[u];	
}

void process(void) {
	cin >> n >> s >> q >> h;
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w; 
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges.emplace_back(u, v, w);
	}
	for (int i = 1, x; i <= s; ++i) {
		cin >> x;
		c[x] = 1; 
	}

	par[h] = -1;
	dfs(h);
	HLD(h);
	// for (int i = 1; i <= n; ++i) cout << w[i] << " " << dp[i] << '\n';
	it.build(1, 1, n);

	for (int i = 1, I, R; i <= q; ++i) {
		cin >> I >> R;
		I--;
		if (edges[I].u != par[edges[I].v]) swap(edges[I].u, edges[I].v);
		if (is_ancestor(edges[I].v, R)) {
			int u = edges[I].v;
			if (dp[u] == INF) {
				cout << "oo\n";
				continue;
			}
			cout << w[R] - Query(u, R) << '\n';
			continue;
		}
		cout << "escaped\n";
	}
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "landslide"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
