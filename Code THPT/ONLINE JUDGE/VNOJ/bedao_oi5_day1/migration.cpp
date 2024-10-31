/*
	Author: Tinhnopro (Tinh nop)
	From: CHV Phu Tho
 */
#include <bits/stdc++.h>

using namespace std;

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
	static_assert(D >= 1, "Init Error");
	template <typename... Args>
	vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};

template <typename T>
struct vec<T, 1> : public vector<T> {
	vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};

template <typename T>
using tpair = pair<T, T>;

template <typename T>
int Size(const T &a) { return a.size(); }

template <typename T1, typename T2>
bool maximize(T1 &a, T2 b) {
	return a < b ? a = b, true : false;
}

template <typename T1, typename T2>
bool minimize(T1 &a, T2 b) {
	return a > b ? a = b, true : false;
}
// End of tempalte

const int MAXN = 5011;
const int64_t INF = (int64_t) 1e18 + 11;

struct Node {
	int v, w;
	
	Node(int _v, int _w) : v(_v), w(_w) {}
};

int n;
vector<Node> adj[MAXN];

int dist[MAXN][MAXN];

int root;

void dfs(int u, int parent = -1) {
	for (auto &x : adj[u]) if (x.v != parent) {
		dist[root][x.v] = dist[root][u] + x.w;
		dfs(x.v, u);
	}
}


void Tinhnopro(void) {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w; 
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for (root = 1; root <= n; ++root) {
		dist[root][root] = 0;
		dfs(root);
	}

	vec<int64_t, 2> dp(n, n, INF);

	dp[1][1] = 0;

	for (int cnt = 2; cnt <= n; ++cnt) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				minimize(dp[i][cnt], dp[j][cnt - 1] + dist[i][j]);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#define name "migration"
	if (fopen(name".inp", "r"))
		freopen(name".inp", "r", stdin),
		freopen(name".out", "w", stdout);

	// int t; cin >> t; while (t--)
	Tinhnopro();

	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s \n";
	return 0;
}
