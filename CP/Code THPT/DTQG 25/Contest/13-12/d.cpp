#include <bits/stdc++.h>

#define TASK ""

using namespace std;

const int maxN = 1e5 + 5;

int n, m;
vector<int> adj[maxN];
int num[maxN], low[maxN];

int cntJoints = 0, cntBridges = 0;

void minimize(int& a, int b) {
	if (a > b) a = b;
}

void dfs(int u, int parent) {
	static int timeDFS = 0;
	low[u] = num[u] = ++timeDFS;

	int child = 1;

	if (parent == -1) child = 0;

	for (int v : adj[u]) {
		if (v == parent) continue;
		if (!num[v]) {
			dfs(v, u);
			minimize(low[u], low[v]);

			if (low[v] > num[u]) cntBridges++;
			if (low[v] >= num[u]) child++;

		} else minimize(low[u], num[v]);
	}

	if (child > 1) cntJoints++;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) if (!num[i]) {
		dfs(i, -1);
	}

	cout << cntJoints << ' ' << cntBridges;
}

