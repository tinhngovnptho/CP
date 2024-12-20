#include <bits/stdc++.h>

#define TASK "impeval"

using namespace std;

using i64 = long long;

const int maxN = 1e5 + 5; 

struct Node {
	int v, w; 

	Node (int _v = 0, int _w = 0) : v(_v), w(_w) {}
};

struct edge_t {
	int u, v, w; 

	edge_t (int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
};

int n, m, q; 
vector<Node> adj[maxN]; 
edge_t edges[maxN], queries[maxN]; 	

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> m >> q; 
	for (int i = 1; i <= m; ++i) {
		int u, v, w; 
		cin >> u >> v >> w; 
		edges[i] = edge_t(u, v, w); 
		adj[u].emplace_back(v, w); 
		adj[v].emplace_back(u, w);
	}

	for (int i = 1; i <= q; ++i) 
		cin >> queries[i].u >> queries[i].v >> queries[i].w; 
	
	
}