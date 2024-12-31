#include <bits/stdc++.h>

#define TASK "impeval"

using namespace std;

using i64 = long long;
using ii64 = pair<i64, int>; 

const int maxN = 5e5 + 5; 

struct Node {
	int v;
	i64 w; 

	Node (int _v = 0, i64 _w = 0) : v(_v), w(_w) {}
	
	bool operator <(const Node& other) const {
		return w > other.w; 
	}
};

struct edge_t {
	int u, v, w; 

	edge_t (int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
};

struct data_t {
	i64 d1, d2;
	int id, id2; 

	data_t(i64 _d1 = 0, i64 _d2 = 0, int _id = 0, int _id2 = 0) : 
		d1(_d1), d2(_d2), id(_id), id2(_id2) {}
	
	bool operator < (const data_t& other) const {
		if (d1 == other.d1) {
			if (d2 == other.d2) {
				if (id == other.id) 
					return id2 < other.id2; 

				return id < other.id; 
			}

			return d2 < other.d2; 
		}

		return d1 < other.d1;
	}
};

template <typename T> 
struct Compressor {
	vector<T> v; 
	
	void add(const T& x) {
		v.push_back(x);
	}

	void compress() {
		sort(v.begin(), v.end()); 
		v.resize(unique(v.begin(), v.end()) - v.begin());
	}

	int get(const T& x) const {
		return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; 
	}
};

struct Fendwick {
	int bit[maxN]; 
	int sz;

	Fendwick() {
		memset(bit, 0, sizeof(bit)); 
		sz = 0;
	}

	void update(int id, int val) {
		for (; id <= sz; id += id & (-id)) bit[id] += val; 
	}

	int get(int u) const {
		int res = 0; 
		for (; u; u -= u & (-u)) res += bit[u]; 
		return res;
	}
};

int n, m, q; 
vector<Node> adj[maxN]; 
edge_t edges[maxN]; 	
i64 dist[3][maxN], result[2][maxN];
vector<data_t> a;
const i64 inf = (i64) 1e18 + 5; 
Compressor<i64> com;
Fendwick fen;

void Dijsktra(int s) {
	for (int i = 1; i <= n; ++i) dist[s][i] = inf; 
	dist[s][s] = 0; 	

	priority_queue<ii64, vector<ii64>, greater<ii64> > pq; 
	pq.emplace(0, s); 

	while (!pq.empty()) {
		int u = pq.top().second; 
		i64 d_u = pq.top().first; 
		pq.pop();

		if (d_u > dist[s][u]) continue;

		for (Node x : adj[u]) {
			int v = x.v; 
			i64 w = x.w; 
		
			if (dist[s][v] > dist[s][u] + w) {
				dist[s][v] = dist[s][u] + w; 
				pq.emplace(dist[s][v], v); 
			}
		}
	}
}	

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

	Dijsktra(1); 
	Dijsktra(2); 

	for (int i = 1; i <= n; ++i) {
		com.add(dist[1][i]); 
		com.add(dist[2][i]);
		// cout << dist[1][i] << ' ' << dist[2][i] << '\n';
		a.emplace_back(dist[1][i], dist[2][i], 0, 0);
	}

	for (int i = 1; i <= q; ++i) {
		int u, v, w, idx; 
		cin >> idx >> w;

		tie(u, v) = {edges[idx].u, edges[idx].v};

		// cout << u << ' ' << v << ' ' << w << ": ";

		i64 du1 = min(dist[1][u], dist[1][v] + w);
		i64 du2 = min(dist[2][u], dist[2][v] + w);
		i64 dv1 = min(dist[1][v], dist[1][u] + w);
		i64 dv2 = min(dist[2][v], dist[2][u] + w);

		// cout << du1 << ' ' << du2 << ' ' << dv1 << ' ' << dv2 << '\n'; 

		if (dist[1][u] <= du1 && dist[2][u] <= du2) result[0][i]--; 
		if (dist[1][v] <= dv1 && dist[2][v] <= dv2) result[1][i]--;

		a.emplace_back(du1, du2, i, 0); 
		a.emplace_back(dv1, dv2, i, 1);

		com.add(du1); com.add(du2); 
		com.add(dv1); com.add(dv2);
	}

	com.compress(); 
	sort(a.begin(), a.end()); 
	fen.sz = (int)com.v.size();

	for (data_t x : a) {
		i64 d1, d2; 
		int id, id2; 

		tie(d1, d2, id, id2) = {x.d1, x.d2, x.id, x.id2};

		int idx = com.get(d2); 
		result[id2][id] += fen.get(idx) + 1;

		if (id == 0) fen.update(idx, 1); 
	} 

	for (int i = 1; i <= q; ++i) 
		cout << result[0][i] << ' ' << result[1][i] << '\n';
}