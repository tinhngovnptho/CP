/*
	Author: Tinhnopro (Tinh nop)
	From: CHV Phu Tho
 */
#include<bits/stdc++.h>

namespace std {
	// optimize min max
	template<typename T1, typename T2> bool maximize(T1 &a, T2 b) { return a < b ? a = b, 1 : 0; }
	template<typename T1, typename T2> bool minimize(T1 &a, T2 b) { return a > b ? a = b, 1 : 0; }
	// vector
	template<typename T, int D> struct vec : public vector<vec<T, D - 1>> {
		static_assert(D >= 1, "Init error");
		template<typename... Args>
			vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
	};
	template<typename T> struct vec<T, 1> : public vector<T> {
		vec(int n = 0, T val = T()) : vector<T>(n, val) {}
		template<typename InputIt>
			vec(InputIt first, InputIt last) : vector<T>(first, last) {}
	};
	// size
	template<typename T> int Size(const T &a) {  return a.size(); }
}
using namespace std;

const int MAXN = 5e3 + 11; 

int n, m, k; 
vector<int> adj[MAXN];
int dist[MAXN][MAXN], cnt[MAXN][MAXN];
long double E[MAXN];

void BFS(int s) {
	queue<int> q; 
	q.push(s);
	for (int i = 1; i <= n; ++i) dist[s][i] = 1e9;
	dist[s][s] = 0;
	cnt[s][s] = 1; 
	while (Size(q)) {
		int u = q.front();
		q.pop();
		for (int &v : adj[u]) {
			if (dist[s][v] > dist[s][u] + 1) {
				dist[s][v] = dist[s][u] + 1;
				cnt[s][v] = cnt[s][u];
				q.push(v);
			} else if (dist[s][v] == dist[s][u] + 1) cnt[s][v] += cnt[s][u];
		}
	}
}

void process(void) {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		u++; v++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> k;
	for (int i = 1; i <= n; ++i) BFS(i);

	for (int i = 1, u, v; i <= k; ++i) {
		cin >> u >> v; 
		u++; v++;
		for (int w = 1; w <= n; ++w) {
			if (dist[u][w] + dist[w][v] == dist[u][v]) {
				int64_t res1 = 1ll * cnt[u][w] * cnt[w][v];
				// cout << w << ' ' << res1 << ' ' << cnt[u][v] << '\n';
				E[w] +=  (long double) res1 / cnt[u][v];
			}		
		}
	}
	long double max_cost = 0;
	int ans = -1;
	for (int w = 1; w <= n; ++w) {
		if (maximize(max_cost, E[w])) {
			ans = w;
		}
	}
	cout << ans - 1;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "TRAINCENTRE"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}