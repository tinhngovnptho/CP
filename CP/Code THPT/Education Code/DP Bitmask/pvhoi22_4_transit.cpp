  /*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif

using namespace std;

const int MAXN = 1511;
const int MAX = 18;
const int INF = 1e9 + 7;

int n, m, q;
int f[MAX];
int dist[2][MAX][MAXN], cost[MAXN][MAXN];
bool used[MAXN];
int dp[MAX][MAX][1 << MAX];

void minimize(int &a, int b) {
	if (a > b) a = b;
}

void Dijsktra(int s, bool id) {
	for (int i = 1; i <= n; ++i) dist[id][s][i] = INF;
	for (int i = 1; i <= n; ++i) used[i] = false;
	dist[id][s][f[s]] = 0;
	while (true) {
		int best = -1;
		for (int u = 1; u <= n; ++u)
			if (!used[u] && (best < 0 || dist[id][s][u] < dist[id][s][best])) best = u;

		if (best < 0) break;
		used[best] = true;

		for (int v = 1; v <= n; ++ v)
			minimize(dist[id][s][v], dist[id][s][best] + (id ? cost[v][best] : cost[best][v]));
	}
}

void solve_dp(void) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int mask = 0; mask < (1 << m); ++ mask) {
				dp[i][j][mask] = INF;
			}
		}
	}

	for (int i = 0; i < m; ++i) dp[i][i][(1 << i)] = 0;

	for (int mask = 0; mask < (1 << m); ++mask) {
		for (int bit_i = mask; bit_i > 0; bit_i ^= bit_i & -bit_i) {
			int i = __builtin_ctz(bit_i & -bit_i);
			for (int bit_j = mask; bit_j > 0; bit_j ^= bit_j & -bit_j) {
				int j = __builtin_ctz(bit_j & -bit_j);

				if (dp[i][j][mask] == INF) continue;

				int rev_mask = ((1 << m) - 1) ^ mask;

				for (int bit_k = rev_mask; bit_k > 0; bit_k ^= bit_k & -bit_k) {
					int k = __builtin_ctz(bit_k & -bit_k);
					minimize(dp[i][k][mask | (1 << k)], dp[i][j][mask] + dist[0][j][f[k]]);
				}
			}
		}
	}
}

int query(int from, int to) {
	int res = INF;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			minimize(res, dist[1][i][from] + dp[i][j][(1 << m) - 1] + dist[0][j][to]);
		}
	}
	return res;
}

void run_case(void) {
	cin >> n >> m >> q;

	for (int i = 0; i < m; ++i) cin >> f[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < m; ++i) {
		Dijsktra(i, 0);
		Dijsktra(i, 1);
	}
	solve_dp();

	for (int i = 1, from, to; i <= q; ++i) {
		cin >> from >> to;
		cout << query(from, to) << ' ';
	}
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("pvhoi22_4_transit.inp", "r", stdin);
	freopen("pvhoi22_4_transit.out", "w", stdout);

	int tests = 1;
//	cin >> tests;
	while (tests--) run_case();
//	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
