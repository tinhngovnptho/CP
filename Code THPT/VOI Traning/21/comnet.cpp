/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1011;

int n, k, a, b;
vector <int> adj[MAXN];

namespace Sub1 {
	int d[MAXN];

	bool check(void) {
		return ((n <= 100) && (k == 2));
	}

	void dfs(int u, int parent = -1) {
		for (int &v : adj[u]) if (v != parent) {
			d[v] = d[u] + 1;
			dfs(v, u);
		}
	}

	void solve(void) {
		int cnt = 0;
		for (int i = 1; i < n; ++i) {
			memset(d, 0, sizeof(d));
			dfs(i);
			for (int j = i + 1; j <= n; ++j) {
				if (d[j] >= a && d[j] <= b) cnt++;
			}
		}
		cout << cnt;

	}
}

namespace Sub2 {
	const int LOG = 12;
	int par[LOG + 1][MAXN], depth[MAXN];

	bool check(void) {
		return (n <= 100 && (k == 3));
	}

	void dfs(int u, int parent) {
		par[0][u] = parent;
		for (int i = 1; i <= LOG; ++i) par[i][u] = par[i - 1][par[i - 1][u]];
		for (int &v : adj[u]) if (v != parent) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}

	int lca(int u, int v) {
		if (u == v) return u;
		if (depth[u] < depth[v]) swap(u, v);
		int h = depth[u] - depth[v];
		for (int i = LOG; ~i; --i) if ((h >> i) & 1) {
			u = par[i][u];
		}
		if (u == v) return u;
		for (int i = LOG; ~i; --i) if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
		return par[0][u];
	}

	int dist(int u, int v) {
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	}

	void solve(void) {
		int cnt = 0;
		dfs(1, 1);
		for (int u = 1; u <= n; ++u) {
			for (int v = u + 1; v <= n; ++v) {
				for (int c = v + 1; c <= n; ++c) {
					int d = dist(u, v);
					int x = lca(u, v) ^ lca(v, c) ^ lca(u, c);
					d += dist(x, c);
					if (d >= a && d <= b) {
						cnt++;
					}
				}
			}
		}
		cout << cnt;
	}
}

namespace Sub5 {
	int64_t dp[MAXN][5][MAXN];
	int sz[MAXN];

	void dfs(int u, int parent = -1) {
		sz[u] = 1;
		dp[u][0][0] = dp[u][1][0] = 1;
		for (int &v : adj[u]) if (v != parent) {
			dfs(v, u);

			for (int cntu = k; ~cntu; --cntu) {
				for (int cntv = 1; cntv <= k; ++cntv) {
					if (cntu + cntv <= k) {
						for (int sumu = sz[u]; ~sumu; --sumu) {
							for (int sumv = 0; sumv <= sz[v]; ++sumv) {
								dp[u][cntu + cntv][sumu + sumv + (cntv < k)] += 1ll * dp[u][cntu][sumu] * dp[v][cntv][sumv];
							}
						}
					}
				}
			}

			sz[u] += sz[v];
		}
	}

	void solve(void) {
		dfs(1, 1);
		int64_t ans = 0;
		for (int i = a; i <= b; ++i) ans += dp[1][k][i];
		cout << ans;
	}
}

void run_case(void) {
	cin >> n >> k >> a >> b;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	Sub5::solve();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("comnet.inp", "r", stdin);
	freopen("comnet.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
