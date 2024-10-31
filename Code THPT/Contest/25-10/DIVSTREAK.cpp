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

const int64_t INF = 1e18 + 11; 

int64_t gcd(int64_t a, int64_t b) {
	int64_t r; 
	while (b) {
		r = a % b; 
		a = b; 
		b = r;
	}
	return a; 
} 

int64_t lcm(int64_t a, int64_t b) {
	return a / gcd(a, b) * b; 
}

int64_t lcm_opt(int64_t l, int64_t r) {
	int64_t res = 1; 
	for (int64_t i = l; i <= r; ++i) {
		res = lcm(res, i);
		if (res < 0) return INF;
	}
	return res;
}

void process(void) {
	int64_t l, r, k; cin >> l >> r >> k;
	if (k > 41) {
		cout << 0 << '\n';
		return ;
	}
	r--;
	l--;

	int64_t d1 = lcm_opt(2, k);
	int64_t d2 = lcm_opt(2, k + 1);
	int64_t res = r / d1 - (l - 1) / d1; 
	res -= r / d2 - (l - 1) / d2; 
	cout << res << '\n'; 
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "DIVSTREAK"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
