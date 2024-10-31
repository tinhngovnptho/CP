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

using ii = pair<int, int>;

const int MAXN = 511; 

struct Edge {
	int u, v, w;
	Edge() {
		u = v = w = 0;
	}
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {} 
};

int n, m, k; 
int a[MAXN][MAXN], d[MAXN][MAXN];
vector<Edge> edges; 
int c[MAXN * MAXN + 11];

struct DSU {
	int lab[MAXN * MAXN + 11], cnt[MAXN * MAXN + 11];

	void init(int n) {
		for (int i = 1; i <= n; ++i) {
			lab[i] = -1;
			cnt[i] = c[i];
		}
	}

	int find_par(int u) {
		return lab[u] < 0 ? u : lab[u] = find_par(lab[u]);
	}

	int sz(int u) {
		u = find_par(u);
		return -lab[u];
	}

	bool join(int u, int v) {
		u = find_par(u);
		v = find_par(v);
		if (u == v) return false; 
		if (lab[u] > lab[v]) {
			swap(u, v);
		}
		lab[u] += lab[v];
		cnt[u] += cnt[v];
		lab[v] = u;  
		return true; 
	}	
} dsu;

bool cmp(const Edge &x, const Edge &y) {
	return x.w < y.w; 
}

int Get(int i, int j) {
	return (i - 1) * m + j;
}

void process(void) {
	cin >> n >> m >> k; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i < n) {
				edges.emplace_back(Get(i, j), Get(i + 1, j), abs(a[i + 1][j] - a[i][j]));
			} 
			if (j < m) {
				edges.emplace_back(Get(i, j), Get(i, j + 1), abs(a[i][j + 1] - a[i][j]));
			}
		}
	}
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> d[i][j];		
			c[Get(i, j)] += d[i][j];	
		}
	}
	dsu.init(m * n);
	int64_t ans = 0;
	for (Edge &x : edges) {
		dsu.join(x.u, x.v);
		int par = dsu.find_par(x.u);
		if (dsu.lab[par] <= -k) {
			// cout << dsu.cnt[par] << '\n';
			ans += 1ll * dsu.cnt[par] * x.w; 
			dsu.cnt[par] = 0;
		}
	}
	cout << ans;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "spiderman"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
