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

const int MAXN = 1e3 + 11; 

int m, n, q;
int a[MAXN][MAXN];
set<pair<int, int> > mark;

struct DSU {
	int lab[MAXN * MAXN + 11], cntE = 0, cntV = 0, cntC = 0;
	
	DSU() {
		memset(lab, -1, sizeof(lab));
		cntC = cntE = cntV = 0;
	} 

	int find_par(int u) {
		return lab[u] < 0 ? u : lab[u] = find_par(lab[u]); 
	}

	void join(int u, int v) {
		if (mark.find({u, v}) == mark.end()) {
			cntE++;
			mark.insert({u, v});
			mark.insert({v, u});
		}
		u = find_par(u);
		v = find_par(v);
		if (u == v) return ;
		if (lab[u] > lab[v]) swap(u, v); 
		if (lab[u] != -1) {
			cntC--;
			cntV += lab[u];
		}
		if (lab[v] != -1) { 
			cntC--;
			cntV += lab[v];
		}
		lab[u] += lab[v];
		lab[v] = u;
		cntC++;
		cntV -= lab[u];
	}
} dsu;

int get(int x, int y) {
	return (x - 1) * n + y;
}

void process(void) {
	cin >> m >> n >> q;
	for (int i = 1, x, y, u, v; i <= q; ++i) {
		cin >> x >> y >> u >> v;
		dsu.join(get(x, y), get(u, v));
		cout << dsu.cntE - dsu.cntV + dsu.cntC << '\n';
	}
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "connect"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
