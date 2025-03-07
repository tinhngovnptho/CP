/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 11;

int n;
vector <pair<int, int> > adj[MAXN];

void dfs(void) {

}

void run_case(void) {
	cin >> n;
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("lqdxeui.inp", "r", stdin);
	freopen("lqdxeui.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
