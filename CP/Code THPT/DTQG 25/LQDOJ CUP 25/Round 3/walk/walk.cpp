#include<bits/stdc++.h>

// Author: Tinhnopro (a.k.a NVT)

using namespace std;

#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define ld long double
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define ONBIT(i, mask) (mask | MASK(i))
#define OFFBIT(i, mask) mask & ~(MASK(i))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 2e5 + 11;

int n, m, k, q;

struct Node {
	int v, w;
	Node() {
		v = w = 0;
	}

	Node(int _v, int _w): v(_v), w(_w) {}
};

struct Query {
	int u, v;

	void read() {
		cin >> u >> v;
	}
};

vector<Node> adj[MAXN];
int x[MAXN];
Query queries[MAXN];
vi nadj[MAXN];

int d[MAXN];

void Dijsktra(void) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	FOR(i, 1, n) d[i] = 1e9 + 11; 
	FOR(i, 1, k) {
		d[x[i]] = 0;
		pq.push({0, x[i]});
	}
	while (!pq.empty()) {
		int u = pq.top().se;
		int d_u = pq.top().fi;
		pq.pop();
		if (d_u > d[u]) continue;
		for (Node& x : adj[u]) {
			int v = x.v;
			int w = x.w;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
}

bool cmp(const int &u, const int &v) {
	return d[u] < d[v];
}

const int LOG = 25;

int par[MAXN], sz[MAXN], depth[MAXN];
int chainHead[MAXN], chainID[MAXN], pos[MAXN], a[MAXN];

void dfs(int u, int parent) {
	sz[u] = 1;
	for (int &v : nadj[u]) if (v != parent) {
		par[v] = u;
		depth[v] = depth[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

int curChain, curPos;

void HLD(int u, int parent) {
	if (!chainHead[curChain]) {
		chainHead[curChain] = u;
	}
	chainID[u] = curChain;
	pos[u] = curPos;
	a[curPos] = u;
	curPos++;

	int nxt = 0;
	for (int v : nadj[u]) if (v != parent) {
		if (!nxt || sz[nxt] < sz[v]) nxt = v; 
	}

	if (nxt) HLD(nxt, u);
	
	for (int v : nadj[u]) if (v != parent && v != nxt) {
		curChain++;
		HLD(v, u);
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

int seg[4 * MAXN];

void build(int id, int l, int r) {
	if (l == r) {
		return void(seg[id] = d[a[l]]);
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);

	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

int getmin(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return 1e9 + 11;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return min(getmin(id << 1, l, mid, u, v), 
			getmin(id << 1 | 1, mid + 1, r, u, v));
}

int query(int u, int v) {
	int lca = LCA(u, v);
	int ans = 1e9 + 11;
	while (chainID[u] != chainID[lca]) {
		int head = chainHead[chainID[u]];
		ans = min(ans, getmin(1, 1, n, pos[head], pos[u]));
		u = par[head];
	}
	while (chainID[v] != chainID[lca]) {
		int head = chainHead[chainID[v]];
		ans = min(ans, getmin(1, 1, n, pos[head], pos[v]));
		v = par[head];
	}
	if (depth[u] > depth[v]) ans = min(ans, getmin(1, 1, n, pos[v], pos[u]));
	else ans = min(ans, getmin(1, 1, n, pos[u], pos[v]));
	return ans;
}

struct Edge {
	int u, v, w;
	Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}

	bool operator >(const Edge &other) const {
		return w > other.w;
	}
};

struct  DSU {
	int lab[MAXN];
	
	DSU() {
		memset(lab, -1, sizeof lab);
	}

	int find_par(int u) {
		return lab[u] > 0 ? lab[u] = find_par(lab[u]) : u;
	}

	bool union_set(int u, int v) {
		u = find_par(u);
		v = find_par(v);
		if (u == v) return false; 
		if (lab[u] > lab[v]) swap(u, v);
		lab[u] += lab[v];
		lab[v] = u;
		return true; 
	} 
} dsu;

vector<Edge> edges;
vector<int> mark;

void FindMST(void) {
	sort(ALL(edges), greater<Edge>());

	mark.assign(m, 0);

	FOR(i, 0, SZ(edges) - 1) {
		if (!dsu.union_set(edges[i].u, edges[i].v)) continue;
		mark[i] = 1; 
	}

	FOR(i, 0, SZ(edges) - 1) if (mark[i]) {
		nadj[edges[i].u].push_back(edges[i].v);
		nadj[edges[i].v].push_back(edges[i].u);
	}
}

void process(void) {
	cin >> n >> m >> k >> q;
	FOR(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		edges.push_back({u, v, w});
	}
	FOR(i, 1, k) cin >> x[i];
	Dijsktra();
	
	for (Edge &x : edges) {
		x.w = min(d[x.u], d[x.v]);
	}

	FindMST();

	dfs(1, 1);
	curChain = curPos = 1;
	HLD(1, 1);
	build(1, 1, n);

	while (q--) {
		int u, v; 
		cin >> u >> v;
		cout << query(u, v) << el;
	}    
}

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#define Task "walk"
	if (fopen(Task".inp", "r")) {
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	return 0;
}
