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

const int MAXN = 3e5 + 11;

struct Data {
	int x, a, b; 
	
	Data() {
		x = a = b = 0;
	}

	void Read(void) {
		cin >> x >> a >> b; 
	}
};

int D, n;
Data d[MAXN];

bool check(int F) {
	
}

void process(void) {
	cin >> n >> D;
	for (int i = 1; i <= n; ++i) {
		d[i].Read();
	}	

	sort(d + 1, d + n + 1, [](const Data &a, const Data &b) -> bool {
		return a.x < b.x; 
	});

	int L = 1, R = D, res = -1;
	while (L <= R) {
		int mid = (L + R) >> 1; 
		if (check(mid)) {
			res = mid; 
			R = mid - 1;
		} else L = mid + 1;
	} 
	cout << res << '\n';
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "ffuel"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
