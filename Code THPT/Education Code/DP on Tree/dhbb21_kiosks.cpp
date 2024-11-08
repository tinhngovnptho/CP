/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 11;
const int MAX = 11;
const int MOD = 1e9 + 7;

int n, k;
int c[MAXN];
vector <int> adj[MAXN];
int dp[MAXN], isDel[MAXN];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += MOD;
}

void dfs(int u, int par = -1) {
	dp[u] = 1;
	for (int v : adj[u]) if ((v ^ par) && !isDel[v]) {
		dfs(v, u);
		dp[u] = 1LL * dp[u] * (dp[v] + 1) % MOD;
	}
}

bool isSubset(int mask, int u) {
	if (u >= k) return false;
	return ((mask >> u) & 1);
}

int cnt(int mask) {
	memset(isDel, false, sizeof(isDel));
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; ++i) if (isSubset(mask, c[i])) isDel[i] = true;

	for (int i = 1; i <= n; ++i) if (!dp[i] && !isDel[i]) dfs(i);

	int ret = 0;
	for (int i = 1; i <= n; ++i) if (!isDel[i]) add(ret, dp[i]);

	return ret;
}

void run_case(void) {
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		c[i]--;
	}
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int res = 0;

	for (int mask = 0; mask < (1 << k); ++mask) {
		if (__builtin_popcount(mask) % 2 == 0) add(res, cnt(mask));
		else sub(res, cnt(mask));
	}

	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("dhbb21_kiosks.inp", "r", stdin);
	freopen("dhbb21_kiosks.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
