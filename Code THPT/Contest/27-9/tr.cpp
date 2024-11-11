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
const int LOG = 20;

int n, q, k;
vi adj[MAXN];
int timeIn[MAXN], timeOut[MAXN], up[MAXN][LOG + 1];

void dfs(int u, int parent) {
	static int timeDFS = 0;
	timeIn[u] = ++timeDFS;
	
	for (int &v : adj[u]) if (v != parent) {
		up[v][0] = u;
		dfs(v, u);
	}

	timeOut[u] = timeDFS;
}

void buildLCA(void) {
	FOR(i, 1, LOG) FOR(u, 1, n) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
}

bool is_act(int u, int v) {
	return timeIn[u] <= timeIn[v] && timeOut[v] <= timeOut[u];
}

int lca(int u, int v) {
	if (is_act(u, v)) return u;
	if (is_act(v, u)) return v;
	FORD(i, LOG, 0) if (!is_act(up[u][i], v)) {
		u = up[u][i];
	}
	return up[u][0];
}

bool cmp(const int &u, const int &v) {
	return timeIn[u] < timeIn[v];
}

vi virAdj[MAXN];    
vector<pii> edges;
int sum[MAXN];
pii idx[MAXN];


void buildVirtualTree(vi &nodes) {
	sort(ALL(nodes), cmp);

	int m = SZ(nodes);
	FOR(i, 0, m - 2) {
		int u = nodes[i];
		int v = nodes[i + 1];
		nodes.push_back(lca(u, v));
	}

	sort(ALL(nodes), cmp);
	nodes.resize(unique(ALL(nodes)) - nodes.begin());

	m = SZ(nodes);

	FOR(i, 0, m - 1) {
		virAdj[i].clear();
	}

	FOR(i, 0, m - 2) {
		int l = lca(nodes[i], nodes[i + 1]);
		int v = nodes[i + 1];
		virAdj[l].push_back(v);
		sum[l]--; sum[v]++;
	}
}

vi ans; 

void dfs2(int u, int parent) {
	for (int &v : adj[u]) if (v != parent) {
		dfs2(v, u);
		sum[u] += sum[v];
	}

	if (sum[u] >= k) {
		ans.push_back(idx[u].second);
	}
}

void process(void) {
	cin >> n >> q >> k;
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u, v});
	}
	
	up[1][0] = 1;
	dfs(1, 1);
	buildLCA();

	FOR(i, 0, SZ(edges) - 1) {
		int u = edges[i].first;
		int v = edges[i].second;
		if (u != up[v][0]) swap(u, v);
		idx[v] = {u, i + 1};
	}

	vi node;
	while (q--) {
		int sz; cin >> sz;
		node.clear();
		FOR(i, 1, sz) {
			int x; cin >> x; 
			node.push_back(x);
		}
		buildVirtualTree(node);
	}
	dfs2(1, 1);
	sort(ALL(ans));
	cout << SZ(ans) << el;
	for (int x : ans) cout << x << " ";
}

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#define Task "tr"
	if (fopen(Task".inp", "r")) {
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	return 0;
}
