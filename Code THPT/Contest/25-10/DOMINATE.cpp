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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
	return uniform_int_distribution<int>(l, r) (rng);
}

const int MAXN = 5e5 + 11; 

int n, q, c[MAXN];
vector<int> adj[MAXN];
int sz[MAXN], par[MAXN], depth[MAXN]; 
int chainHead[MAXN], chainID[MAXN], pos[MAXN], arr[MAXN];
vector<int> idx[MAXN];

void dfs(int u, int parent = -1) {
	sz[u] = 1; 
	for (int &v : adj[u]) if (v != parent) {
		par[v] = u; 
		depth[v] = depth[u] + 1; 
		dfs(v, u);
		sz[u] += sz[v];
	}
}

int curChain = 1, curPos = 1;

void HLD(int u, int parent = -1) {
	if (!chainHead[curChain]) {
		chainHead[curChain] = u; 
	}
	chainID[u] = curChain;
	pos[u] = curPos;
	arr[curPos] = u; 
	idx[c[u]].push_back(curPos);
	curPos++;

	int nxt = 0; 
	for (int &v : adj[u]) if (v != parent) 
		if (nxt == 0 || sz[v] > sz[nxt]) nxt = v; 

	if (nxt) HLD(nxt, u);

	for (int &v : adj[u]) if (v != parent && v != nxt) {
		curChain++;
		HLD(v, u);
	}
}

int LCA(int u, int v) {
	while (chainID[u] != chainID[v]) {
		if (chainID[u] > chainID[v]) {
			u = par[chainHead[chainID[u]]];
		} else {
			v = par[chainHead[chainID[v]]];
		}
	}
	if (depth[u] > depth[v]) return v; 
	return u; 
}

int GetRange(int l, int r, int k) {
	int Left = lower_bound(idx[k].begin(), idx[k].end(), l) - idx[k].begin();
	int Right = upper_bound(idx[k].begin(), idx[k].end(), r) - idx[k].begin() - 1; 
	return Right - Left + 1; 
}

int Query(int u, int v, int k) {
	int lca = LCA(u, v);
	int ans = 0;

	while (chainID[u] != chainID[lca]) {
		int head = chainHead[chainID[u]];
		ans += GetRange(pos[head], pos[u], k);
		u = par[head];
	}

	while (chainID[v] != chainID[lca]) {
		int head = chainHead[chainID[v]];
		ans += GetRange(pos[head], pos[v], k);
		v = par[head];
	}

	if (depth[u] > depth[v]) swap(u, v);
	ans += GetRange(pos[u], pos[v], k);
	return ans; 
}


void process(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) 
		cin >> c[i];

	for (int i = 1; i < n; ++i) {
		int u, v; 
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}	

	dfs(1);
	HLD(1);

	while (q--) {
		int u, v; cin >> u >> v; 
		
		if (pos[u] > pos[v]) swap(u, v);
		// cout << pos[u] << " " << pos[v] << '\n';

		int Sz = depth[v] + depth[u] - 2 * depth[LCA(u, v)] + 1;
		bool check = false; 
		
		for (size_t test = 1; test <= 25; ++test) {
			int k = randInt(pos[u], pos[v]);
			// cout << arr[k] << ' ';
			int color = c[arr[k]];

			if (Query(u, v, color) > Sz / 2) {
				cout << color << '\n';
				check = true;
				break;
			}
		}
		// cout << '\n';

		if (!check) cout << -1 << '\n';
	}

}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "DOMINATE"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
