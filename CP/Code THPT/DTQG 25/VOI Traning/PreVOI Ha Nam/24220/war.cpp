/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-30
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

template <typename T> inline int isize(const T& a) { return a.size(); }

template <typename T1, typename T2> bool maximize(T1& a, T2 b) { return a < b ? a = b, true : false; }
template <typename T1, typename T2> bool minimize(T1& a, T2 b) { return a > b ? a = b, true : false; }

const int maxN = 2011;

struct edge_t {
	int u, v, w;
	edge_t() : u(0), v(0), w(0) {}
	edge_t(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int n, m, T;
vector<pair<int, int> > adj[maxN];
vector<edge_t> edges;

int cp = 0;
bool vist[maxN];

void dfs(int u) {
	vist[u] = true;
	for (auto x : adj[u]) if (!vist[x.first]) dfs(x.first);
}

int lab[maxN];

int find_par(int u) {
	return lab[u] > 0 ? lab[u] = find_par(lab[u]) : u;
}

bool joint(int u, int v) {
	u = find_par(u);
	v = find_par(v);
	if (u == v) return false;

	if (lab[u] > lab[v]) swap(u, v);
	lab[u] += lab[v];
	lab[v] = u;
	return true;
}

bool combine(const edge_t &a, const edge_t &b) {
	return a.w < b.w;
}

vector<int> d;
int low[maxN], num[maxN];

void dfs2(int u) {
	static int timeDFS = 0;
	low[u] = num[u] = ++timeDFS;
	for (auto x : adj[u]) {
		int v = x.first;
		if (!num[v]) {
			dfs2(v);
			minimize(low[v], low[u]);
			if (low[v] == num[u]) {
				d.push_back(x.second);
			}
		} else minimize(low[u], num[v]);
	}
}

void solve1() {
	for (int i = 1; i <= n; ++i) if (!vist[i]) {
		dfs(i);
		cp++;
	}

	if (cp > 1) cout << 0;
	else {

		for (int i = 1; i <= n; ++i) if (!num[i]) dfs2(i);

		memset(lab, -1, sizeof(lab));
		sort(edges.begin(), edges.end(), combine);
		int ans = 1e9, res = 0;
		for (edge_t e : edges) {
			if (!joint(e.u, e.v)) continue;
			minimize(ans, e.w);
			res += e.w;
		}
		minimize(ans, res);
		if (d.size()) {
			cout << *min_element(d.begin(), d.end());
		} else cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("war.inp", "r", stdin);
	freopen("war.out", "w", stdout);

	cin >> T >> n >> m;

	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		u++;
		v++;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges.emplace_back(u, v, w);
	}

	if (T == 1) {
		solve1();
	} else {
		int ans = 0;
		for (edge_t e : edges) ans += e.w;
		cout << ans;
	}
}

