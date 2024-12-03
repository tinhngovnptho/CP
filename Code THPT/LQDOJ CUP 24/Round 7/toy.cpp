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

const int MAXN = 1e6 + 11; 

int n, q; 
int64_t a[MAXN];
int64_t st[4 * MAXN], lazy[4 * MAXN], sum[MAXN];

void build(int id, int l, int r) {
	if (l == r) return void(st[id] = sum[l]);

	int mid = (l + r) >> 1;

	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);

	st[id] = max(st[id << 1], st[id << 1 | 1]);
}

void down(int id) {
	if (!lazy[id]) return ;
	st[id << 1] += lazy[id];
	st[id << 1 | 1] += lazy[id];
	lazy[id << 1] += lazy[id];
	lazy[id << 1 | 1] += lazy[id];
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int64_t val) {
	if (l > v || r < u) return ;
	if (u <= l && r <= v) {
		st[id] += val;
		lazy[id] += val;
		return ;
	}
	down(id);
	int mid = (l + r) >> 1; 
	update(id << 1, l, mid, u, v, val);
	update(id << 1 | 1, mid + 1, r, u, v, val);

	st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int Get(int id, int l, int r, int u, int v) {
	if (u == 0 || v == 0) return 0;
	if (l > v || r < u) return -1;
	if (u <= l && r <= v) return st[id]; 
	down(id);
	int mid = (l + r) >> 1; 
	return max(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
}

int walk(int id, int l, int r, int u, int v, int64_t val) {
	if (l > v || r < u) return -1;
	down(id);
	if (2 * st[id] <= val) return -1; 
	if (l == r) return l;
	int mid = (l + r) >> 1; 
	int Left = walk(id << 1, l, mid, u, v, val);
	if (Left == -1) return walk(id << 1 | 1, mid + 1, r, u, v, val);
	return Left;
}

int64_t bit[MAXN];

void Update(int u, int64_t v) {
	while (u <= n) {
		bit[u] += v;
		u += u & -u;
	}
}

int64_t query(int u) {
	int64_t res = 0;
	while (u > 0) {
		res += bit[u];
		u -= u & -u;
	}
	return res; 
}

void process(void) {
	cin >> n >> q; 
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	build(1, 1, n);
	memset(bit, 0, sizeof(bit));
	for (int i = 1; i <= n; ++i) Update(i, a[i]);
	int type, u, v, mid;
	int64_t res, ans, t;
	while (q--) {
	 	cin >> type >> u >> v;
		if (type == 1) {
			update(1, 1, n, u, n, v - a[u]);
			Update(u, v - a[u]);
			a[u] = v;
		} else {
			res = query(u - 1) + query(v);
			mid = walk(1, 1, n, u, v, res);
			ans = (int64_t)1e18; 
			t = 2 * query(mid);
			minimize(ans, t - res);
			t = 2 * query(mid - 1);
			minimize(ans, res - t);
			cout << ans << '\n';
		}
	}
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "toy"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
