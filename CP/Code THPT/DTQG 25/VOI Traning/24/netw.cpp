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

const int MAXN = 1e5 + 11, INF = 1e9 + 11;
const int MOD = 998244353;

struct Node {
	int v, w;
	Node() {
		v = w = 0;
	}
	Node(int _v, int _w) : v(_v), w(_w) {}
};

int n;
vector<Node> adj[MAXN];

namespace Sub1 {
	int64_t res = 0;
	void dfs(int u, int cmin, int depth, int parent = -1) {
		res += 1ll * cmin * depth * depth;
		res %= MOD;
		for (Node &x : adj[u]) if (x.v != parent) {
			dfs(x.v, min(x.w, cmin), depth + 1, u);
		}
	}
	void solve(void) {
		for (int i = 1; i <= n; ++i) {
			res = 0;
			dfs(i, 1e9, 0);
			cout << res << '\n';
		}
	}
}

int64_t sum(int x) {
	return (1ll * x * (x + 1) * (2 * x + 1) / 6) % MOD;
}

#define Mask(x) (1ll << (x))
#define Log2(x) (63 - __builtin_clzll(x))

namespace Sub2 {
	int a[MAXN];
	const int LOG = 20;

	struct RMQ {
		int st[LOG + 1][MAXN];

		void build(void) {
			for (int i = 1; i < n; ++i) st[0][i] = a[i];
			for (int j = 1; j <= LOG; ++j) {
				for (int i = 1; i + Mask(j) - 1 < n; ++i) {
					st[j][i] = min(st[j - 1][i], st[j - 1][i + Mask(j - 1)]);
				}
			}
		}

		int get(int l, int r) {
			int k = Log2(r - l + 1);
			return min(st[k][l], st[k][r - Mask(k) + 1]);
		}
	} rmq;

	bool check(void) {
		int cnt = 1;
		for (int i = 1; i <= n; ++i) {
			bool check = false;
			for (Node &x : adj[i]) {
				if (x.w > 2) return false;
				if (i < n && x.v == i + 1) {
					check = true;
					a[cnt] = x.w;
					cnt++;
				}
			}
			if (i < n && !check) return false;
		}
		return true;
	}

	void solve(void) {
		rmq.build();
		for (int i = 1; i <= n; ++i) {
			int64_t res = sum(n - i) + sum(i - 1);
			int l = i + 1, r = n, idx = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (rmq.get(i, mid - 1) == 2) {
					idx = mid;
					l = mid + 1;
				} else r = mid - 1;
			}
			if (idx != -1) res += sum(idx - i);
			l = 1; r = i - 1; idx = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (rmq.get(mid, i - 1) == 2) {
					idx = mid;
					r = mid - 1;
				} else l = mid + 1;
			}
			if (idx != -1) res += sum(i - idx);
			res %= MOD;
			cout << res << '\n';
		}
	}
}

namespace Subfull {
	struct Data {
		int dist, cost, idx; 
		Data(int d, int c, int i) : dist(d), cost(c), idx(i) {}
	};

	vector<Data> List;

	int dist[MAXN], cmin[MAXN], isDel[MAXN], sz[MAXN];
	int res[MAXN];

	void countChild(int u, int parent = -1) {
		sz[u] = 1;
		for (Node &x : adj[u]) if (x.v != parent && !isDel[x.v]) {
			countChild(x.v, u);
			sz[u] += sz[x.v];
		}
	}

	int findCentroid(int u, const int &Sz, int parent = -1) {
		for (Node &x : adj[u]) if (x.v != parent && !isDel[x.v]) {
			if (sz[x.v] > Sz) {
				return findCentroid(x.v,  Sz, u);
			}
		}
		return u;
	}

	void add(int &a, int b) {
		a += b;
		if (a < 0) a += 2 * MOD;
		if (a >= MOD) a -= MOD;
	}

	int sqr(int x) {
		return (1ll * x * x) % MOD;
	}

	void dfs(int u, int d, int w, int parent = -1) {
		List.emplace_back(d, w, u);
		for (auto &x : adj[u]) if (!isDel[x.v] && x.v != parent) {
			dfs(x.v, d + 1, min(w, x.w), u);
		}
	}

	void add(signed val) {
		sort(List.begin(), List.end(), [](const Data &a, const Data &b) {
			return a.cost < b.cost;
		});
		int s1 = List[0].cost;
		int s2 = 1ll * List[0].dist * List[0].cost % MOD;
		int s3 = 1ll * sqr(List[0].dist) * List[0].cost % MOD;
		
		for (int i = 1; i < Size(List); ++i) {
			int u = List[i].idx;
			add(res[u], val * s3);
			add(res[u], 1ll * val * s2 * 2 * List[i].dist % MOD);
			add(res[u], 1ll * val * sqr(List[i].dist) * s1 % MOD);

			add(s1, List[i].cost % MOD);
			add(s2, 1ll * List[i].dist * List[i].cost % MOD);
			add(s3, 1ll * sqr(List[i].dist) * List[i].cost % MOD);
		}

		s1 = List.back().dist;
		s2 = sqr(List.back().dist);

		int Sz = Size(List);

		for (int i = Size(List) - 2; i >= 0; --i) {
			int u = List[i].idx;
			add(res[u], 1ll * val * (Sz - i - 1) * sqr(List[i].dist) * List[i].cost % MOD);
			add(res[u], 1ll * val * List[i].cost * s2 % MOD);
			add(res[u], 1ll * val * 2 * List[i].dist * List[i].cost * s1 % MOD);

			add(s1, List[i].dist);
			add(s2, sqr(List[i].dist));
		}
		List.clear();
	}

	void centroid_decomp(int u) {
		countChild(u);
		int Sz = sz[u] >> 1;
		int centroid = findCentroid(u, Sz);

		for (auto &x : adj[centroid]) if (!isDel[x.v]) {
			dfs(x.v, 1, x.w, centroid);
			add(-1);
		}

		dfs(centroid, 0, INF);
		add(1);

		isDel[centroid] = true;
		for (Node &x : adj[centroid]) if (!isDel[x.v]) {
			centroid_decomp(x.v);
		}
	}

	void solve(void) {
		centroid_decomp(1);
		for (int i = 1; i <= n; ++i) cout << res[i] << '\n';
	}
}

void process(void) {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	Subfull::solve();
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "netw"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
