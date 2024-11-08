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

const int MAXN = 1e5 + 11;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w)  : u(_u), v(_v), w(_w) {}
};

struct Node {
    int v, w;
    Node(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, p;
vector<Node> adj[MAXN];
vector<Edge> edges;

namespace Sub1 {
	void solve(void) {
		for (int i = 1)
	}
};

void process(void) {
    cin >> n >> m >> p;
    for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    if (m <= 1000 && p <= 1000) return void(Sub1::solve());
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "impeval"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
