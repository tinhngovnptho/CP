/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-27
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

const int maxN = 1511;
const int maxM = 5011;
const int inf = 1e9 + 11, mod = 1e9 + 7;

using ii = pair<int, int>;
template<class T> using priority_queueg = priority_queue<T, vector<T>, greater<T>>;

struct Node {
	int v, w;
	Node() : v(0), w(0) {}
	Node(int _v, int _w) : v(_v), w(_w) {}
};

struct Edge {
	int u, v, w;
	Edge() : u(0), v(0), w(0) {}
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int n, m;
vector<Node> in[maxN], out[maxN];
Edge edges[maxM];
int minDist[maxN];
int64_t dpL[maxN], dpR[maxN], answer[maxM];

void fixmod(int64_t &x) {
	x %= mod;
}

void Dijsktra(int s) {
	for (int i = 1; i <= n; ++i) minDist[i] = inf;
	minDist[s] = 0;
	priority_queueg<ii> pq;
	pq.emplace(0, s);
	while (!pq.empty()) {
		int d_u = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d_u > minDist[u]) continue;
		for (Node x : in[u]) {
			int v = x.v;
			int w = x.w;
			if (minDist[v] > minDist[u] + w) {
				minDist[v] = minDist[u] + w;
				pq.emplace(minDist[v], v);
			}
		}
	}
}

int64_t calcOut(const int &s, int u) {
	if (u == s) return 1;
	if (~dpL[u]) return dpL[u];

	int64_t cur = 0;

	for (Node x : out[u]) {
		int v = x.v;
		int w = x.w;
		if (minDist[v] + w == minDist[u]) {
			cur += calcOut(s, v);
			fixmod(cur);
		}
	}

	return dpL[u] = cur;
}

int64_t calcIn(const int &s, int u) {
	if (~dpR[u]) return dpR[u];

	int64_t cur = 1;

	for (Node x : in[u]) {
		int v = x.v;
		int w = x.w;
		if (minDist[u] + w == minDist[v]) {
			cur += calcIn(s, v);
			fixmod(cur);
		}
	}

	return dpR[u] = cur;
}

void solve(int root) {
	Dijsktra(root);
	for (int i = 1; i <= n; ++i) {
		dpL[i] = dpR[i] = -1;
	}
	for (int i = 1; i <= m; ++i) {
		int u = edges[i].u;
		int v = edges[i].v;
		if (minDist[u] >= inf || minDist[v] >= inf) continue;
		if (minDist[v] == minDist[u] + edges[i].w) {
			answer[i] += calcOut(root, u) * calcIn(root, v) % mod;
			fixmod(answer[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("shortest.inp", "r", stdin);
	freopen("shortest.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		in[u].emplace_back(v, w);
		out[v].emplace_back(u, w);
		edges[i] = Edge(u, v, w);
	}

	for (int i = 1; i <= n; ++i) solve(i);

	for (int i = 1; i <= m; ++i) cout << answer[i] << '\n';
}
