/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 11;
const int INF = 1e9 + 11;

struct Node {
	int v, w, id;
	Node() { v = w = id = 0; }
	Node(int _v, int _w, int _id) : v(_v), w(_w), id(_id) {}
};

struct Data {
    int dist, id, u;
    Data(int _dist, int _id, int _u): dist(_dist), id(_id), u(_u) {}

    bool operator <(const Data& other) const {
        return dist > other.dist;
    }
};

int n, m, l, k, p;
vector<Node> adj[MAXN];
int d[MAXN], vist[MAXN], dist[MAXN][12];

void Dijsktra(int s) {
	for (int i = 1; i <= n; ++i) for (int j = 0; j <= k; ++j) dist[i][j] = INF;
	priority_queue<Data> pq;
	pq.emplace(0, 0, s);
	dist[s][0] = 0;
	while (!pq.empty()) {
		int u = pq.top().u;
		int dist_u = pq.top().dist;
		int id = pq.top().id;
		pq.pop();
		if (dist_u > dist[u][id]) continue ;
		for (Node x : adj[u]) {
			if (x.id == 1 && id < k) {
				if (dist[x.v][id + 1] > dist[u][id] + x.w) {
					dist[x.v][id + 1] = dist[u][id] + x.w;
					pq.emplace(dist[x.v][id + 1], id + 1, x.v);
				}
			} else if (x.id == 0) {
				if (dist[x.v][id] > dist[u][id] + x.w) {
					dist[x.v][id] = dist[u][id] + x.w;
					pq.emplace(dist[x.v][id], id, x.v);
				}
			}
		}
	}
}

set<pair<int, int>> S;

void bfs(int s) {
	static queue<int> q;
	while (!q.empty()) q.pop();
	memset(d, 0, sizeof(d));
	memset(vist, 0, sizeof(vist));
	q.push(s);
	vist[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (Node x : adj[u]) if (!vist[x.v]) {
			d[x.v] = d[u] + 1;
			if (d[x.v] <= l) {
				S.emplace(min(x.v, s), max(x.v, s));
				vist[x.v] = 1;
				q.push(x.v);
			} else break;
		}
	}
}

void run_case(void) {
	cin >> n >> m >> p >> l >> k;

	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w, 0);
		adj[v].emplace_back(u, w, 0);
	}

	for (int i = 1; i <= n; ++i) bfs(i);

	for (auto x : S) {
		int u = x.first;
		int v = x.second;
		adj[u].emplace_back(v, p, 1);
		adj[v].emplace_back(u, p, 1);
	}

	Dijsktra(1);

	int res = INF;
	for (int i = 0; i <= k; ++i) {
		res = min(res, dist[n][i]);
	}
	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr)	;

	freopen("minpath.inp", "r", stdin);
	freopen("minpath.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
