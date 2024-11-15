/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-14
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#define ALL(v) (v).begin(), (v).end()
#define ssize(s) (int) (s).size()

#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template <typename A, typename B> bool minimize(A &a, B b)  { return a > b ? a = b, true : false; }
template <typename A, typename B> bool maximize(A &a, B b)  { return a < b ? a = b, true : false; }
//} end of template

const int MAXN = (int) 1e6 + 11;

struct Node {
	int v, w;
	Node() { v = w = 0; }
	Node(int _v, int _w) : v(_v), w(_w) {}
};

int n;
vector<Node> adj[MAXN];
int cost[MAXN];
unordered_map<int, pair<int, int> > mark;

void dfs(int u, int parent = -1) {
	for (Node &x : adj[u]) if (x.v ^ parent) {
		cost[x.v] = cost[u] ^ x.w;
		dfs(x.v, u);
	}
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	file("J");
//__________________________________
	cin >> n;
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	dfs(1);

	for (int i = 1, cnt = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j, ++cnt) {
			if (cnt > 1e6) break;
			int c = cost[i] ^ cost[j];
			if (mark.find(c) != mark.end()) {
				cout << i << ' ' << j << ' ' << mark[c].first << ' ' << mark[c].second;
				return 0;
			} else {
				mark[c] = make_pair(i, j);
			}
		}
	}
	cout << -1;
}
