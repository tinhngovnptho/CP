/**
 * Author: tinhnopro (tinh nop)
 * Created: 2024-12-11
 */
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define TASK "salary"

using namespace std;

//mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline void setIO() {
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}
}

const int maxN = 1e5 + 5;

struct SegmentTree {
	struct node_t {
		int64_t lazy, val;

		node_t() : lazy(0), val(0) {}
		node_t(int64_t _lazy, int64_t _val) : lazy(_lazy), val(_val) {}
	};

	node_t st[4 * maxN];

	SegmentTree() {
		for (int i = 1; i < 4 * maxN; ++i) st[i] = node_t();
	}

	void update(int id, int l, int r, int u,  int v, int val) {

	}
};

int n, q;
vector<pair<int, int64_t> > adj[maxN];
int timeIn[maxN], timeOut[maxN];

void dfs(int u) {
	static int timeDFS = 0;
	timeIn[u] = ++timeDFS;

	for (int v : adj[u]) {
		dfs(v);
	}

	timeOut[u] = timeDFS;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(false);
	setIO();
	cin >> n >> q;
	for (int i = 1, v, w; i < n; ++i) {
		cin >> w >> v;
		adj[v].emplace_back(v, w);
	}

	dfs(1);

	for (int i = 1; i <= n; ++i)
}

