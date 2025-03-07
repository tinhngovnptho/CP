/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 11;

vector <int> adj[MAXN];
int c[MAXN], n, cnt[MAXN], cntE = 0;

void dfs(int u, int parent = -1) {
	for (int v : adj[u]) if (v != parent) {
		if (c[u] != c[v]) {
			cntE++;
			cnt[u]++;
			cnt[v]++;
		}
		dfs(v, u);
	}
}

void run_case(void) {
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) cin >> c[i];

	dfs(1);
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == cntE) {
			ans.push_back(i);
		}
	}
	if (ans.empty()) return void(cout << "NO");
	cout << "YES\n";
	for (int x : ans) cout << x << ' ';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("bedao_r08_kingdom.inp", "r", stdin);
	freopen("bedao_r08_kingdom.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
