#include <bits/stdc++.h>

#define TASK ""

using namespace std;

constexpr int maxN = 3e5 + 5;

int numNodes, numEdges;
vector<int> adj[maxN], st;
int num[maxN], low[maxN], del[maxN];
int cntCC = 0;

void dfs(int u) {
	static int timeDFS = 0;
	low[u] = num[u] = ++timeDFS;

	st.push_back(u);

	for (int v : adj[u]) {
		if (del[v]) continue;
		if (!num[v]) {
			dfs(v);

			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], num[v]);
	}

	if (low[u] == num[u]) {
		int v = 0;
		cntCC++;
		while (v != u) {
			v = st.back();
			del[v] = 1;
			st.pop_back();
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> numNodes >> numEdges;
	for (int i = 1; i <= numEdges; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= numNodes; ++i) if (!num[i]) {
		dfs(i);
	}

	cout << cntCC;
}

