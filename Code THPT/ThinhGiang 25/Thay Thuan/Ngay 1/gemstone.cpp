/*
	Author: Tinhnopro (Tinh nop)
	From: CHV Phu Tho
	MLE
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

struct Stone {
	int a[3];
	Stone() {
		a[0] = a[1] = a[2] = 0;
	}

	Stone(int _x, int _y, int _z) {
		a[0] = _x;
		a[1] = _y;
		a[2] = _z;
	}

	void Read(void) {
		cin >> a[0] >> a[1] >> a[2];
	}
};

const int MAXN = 5e5 + 11;
const int INF = 1e9 + 11;

int n, A, B;
vec<Stone, 1> stones;
vector<pair<int, int>> adj[MAXN];
vector<int> v, List[MAXN];
int d[MAXN], vist[MAXN];

void process(void) {
	cin >> n >> A >> B;
	stones.clear();
	stones.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		stones[i].Read();
		v.emplace_back(stones[i].a[0]);
		v.emplace_back(stones[i].a[1]);
		v.emplace_back(stones[i].a[2]);
		List[stones[i].a[0]].push_back(i);
		List[stones[i].a[1]].push_back(i);
		List[stones[i].a[2]].push_back(i);
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	int virNode = n;

	for (int &x : v) {
		virNode++;
		sort(List[x].begin(), List[x].end());
		List[x].resize(unique(List[x].begin(), List[x].end()) - List[x].begin());

		for (int &a : List[x]) {
			adj[virNode].emplace_back(a, 0);
			adj[a].emplace_back(virNode, 1);
		}
	}

	for (int i = 1; i <= virNode; ++i) {
		d[i] = INF;
		vist[i] = 0;
	}

	d[A] = 0;

	deque<int> dq; 
	dq.push_front(A);

	while (Size(dq)) {
		int u = dq.front();
		dq.pop_front();
		if (vist[u]) continue;
		vist[u] = 1; 
		for (auto &x : adj[u]) {
			if (d[x.first] > d[u] + x.second) {
				d[x.first] = d[u] + x.second;
				if (x.second) dq.push_back(x.first);
				else dq.push_front(x.first);
			}
		}
	}

	cout << (d[B] == INF ? -1 : d[B]) << '\n';

	for (int i = 1; i <= virNode; ++i) adj[i].clear();
	for (int &x : v) {
		List[x].clear();
	}
	v.clear();
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "gemstone"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
