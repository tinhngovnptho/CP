#include <bits/stdc++.h>

#define TASK "grandelection"

using namespace std;

inline void setIO() {
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}
}

//mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxN = 1e5 + 5;
const int LOG = 19;

int n, x[maxN], v[maxN];
vector<int> adj[maxN], vadj[maxN], divs[maxN];
int up[LOG + 1][maxN], timeIn[maxN], timeOut[maxN], depth[maxN];

vector<int> list_divs, list_nodes[maxN];
int mark[maxN];
int64_t dp[maxN];

void sieve() {
	for (int i = 2; i < maxN; ++i) {
		for (int j = i; j < maxN; j += i) divs[j].push_back(i);
	}
}

void dfs(int u) {
	static int timeDFS = 0;
	timeIn[u] = ++timeDFS;

	for (int v : adj[u]) {
		depth[v] = depth[u] + 1;
		up[0][v] = u;

		for (int i = 1; i <= LOG; ++i)
			up[i][v] = up[i - 1][up[i - 1][v]];

		dfs(v);
	}

	timeOut[u] = timeDFS;
}

int lca(int u, int v) {
	if (u == v) return u;

	if (depth[u] < depth[v]) swap(u, v);

	int k = depth[u] - depth[v];

	for (int i = 0; (1 << i) <= k; ++i)
		if ((k >> i) & 1) u = up[i][u];

	if (u == v) return u;

	for (int i = LOG; ~i; --i)
		if (up[i][v] != up[i][u]) u = up[i][u], v = up[i][v];

	return up[0][u];
}

bool combine(const int& x, const int& y) {
	return timeIn[x] < timeIn[y];
}

void buildVTree(vector<int>&  nodes) {
	sort(nodes.begin(), nodes.end(), combine);

	int m = nodes.size() - 1;

	for (size_t i = 0; i < m; ++i) {
		int u = nodes[i];
		int v = nodes[i + 1];
		nodes.push_back(lca(u, v));
	}

	sort(nodes.begin(), nodes.end(), combine);

	nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());

	for (size_t i = 0; i < nodes.size(); ++i) {
		int u = nodes[i];
		vadj[u].clear();
		dp[u] = -1;
	}

	for (size_t i = 0; i < nodes.size() - 1; ++i) {
		int u = nodes[i];
		int v = nodes[i + 1];
		vadj[lca(u, v)].push_back(v);
	}
}

void calc(int u, const int& D) {
	dp[u] = 0;
	for (int v : vadj[u]) {
		calc(v, D);
		dp[u] += dp[v];
	}
	if (x[u] % D == 0) dp[u] = max(dp[u], (int64_t) v[u]);
}

void solve() {
	cin >> n;
	for (int i = 2, p; i <= n; ++i) {
		cin >> p;
		adj[p].push_back(i);
	}

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> v[i];
	}

	up[0][1] = 1;
	dfs(1);

	memset(mark, 0, sizeof(mark));
	list_divs.clear();

	for (int i = 1; i <= n; ++i) {
		for (int d : divs[x[i]]) {
			if (!mark[d]) {
				mark[d] = 1;
				list_nodes[d].clear();
				list_divs.push_back(d);
			}
			list_nodes[d].push_back(i);
		}
	}

	int64_t ans = -1;

	for (int d : list_divs) {
		buildVTree(list_nodes[d]);
		for (int u : list_nodes[d]) if (dp[u] == -1) {
			calc(u, d);
			ans = max(ans, 1LL * d * dp[u]);
			break;
		}
	}

	cout << ans << '\n';

	for (int i = 1; i <= n; ++i) adj[i].clear();
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	setIO();

	sieve();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
