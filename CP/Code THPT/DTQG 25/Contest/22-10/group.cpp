/*
	Author: Tinhnopro (Tinh nop)
	From: CHV with luv <3
	while (true) coding();
*/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second

#define all(v) (v).begin(), (v).end()
#define size(v) int((v).size())
#define eb emplace_back

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

#define Mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | Mask(i))
#define offbit(i, mask) (mask & ~(Mask(i)))
#define cntbit(x) __builtin_popcountll(x)
#define Log2(x) (63 - __builtin_clzll(x))

using namespace std;

using db = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;

template<class X, class Y> bool maximize(X &a, Y b) { 
	return a < b ? a = b, 1 : 0; 
}

template<class X, class Y> bool minimize(X &a, Y b) { 
	return a > b ? a = b, 1 : 0; 
}

// const int dx[8] = {+1, -1, +0, +0, +1, -1, +1, -1}, dy[8] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int INF = 1e9 + 11, MAXN = 5e5 + 11, MOD = 1e9 + 7; 
// const int64_t INFF = (int64_t) 1e18 + 7;
//_______________________________________________________________________________________________
int n, m, q;

struct DSU {
	int lab[MAXN], used[MAXN];
	int cnt, sz;

	DSU() {
		memset(lab, -1, sizeof(lab));
		memset(used, 0, sizeof(used));
		cnt = sz = 0;
	}

	int find_par(int u) {
		return (lab[u] < 0 ? u : lab[u] = find_par(lab[u]));
	}

	void join(int u, int v) {
		if (used[u] == 0 && used[v] == 0) {
			cnt++;
			sz += 2; 
		} else if (used[u] == 0 || used[v] == 0) {
			sz++;
		}
		u = find_par(u);
		v = find_par(v);
		if (u == v) return ; 
		if (lab[u] > lab[v]) swap(u, v);
		lab[u] += lab[v];
		lab[v] = u;
		used[u] = used[v] = 1; 
	}
} dsu;

void process(void) {
	cin >> n >> m;
	FOR(i, 1, m) {
		int u, v; cin >> u >> v;
		dsu.join(u, v);  
	}
	cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		dsu.join(u, v);
		// cout << dsu.cnt << " " << dsu.sz << el;
		if (dsu.cnt == 1 && dsu.sz < n) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "group"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin); 
		freopen(name".out", "w", stdout);
	}
	//____________________________________________________
	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
