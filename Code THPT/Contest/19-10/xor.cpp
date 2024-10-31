/* 
	Author: Tinhnopro (Tinh nop)
	while (true) coding();
*/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

using namespace std;
namespace std {
	template <class X, class Y> bool maximize(X &a, Y b) { 
		return a < b ? a = b, 1 : 0; 
	}

	template <class X, class Y> bool minimize(X &a, Y b) { 
		return a > b ? a = b, 1 : 0; 
	}

	template <class T> int isize(const T &a) { return a.size(); }

	template <typename T, int D> struct vec : public vector<vec<T, D - 1>> {
		static_assert(D >= 1, "Init error");
		template <typename... Args> vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
	};

	template <typename T> struct vec<T, 1> : public vector<T> {
		vec(int n = 0, T val = T()) : vector<T>(n, val) {}
	};
}

using ii = pair<int, int>;
using db = long double; 

// const int MAXN = 5e5 + 11, MOD = 1e9 + 7, INF = 1e9 + 11;
// const int64_t INFF =  1e18 + 11;


void process(void) {
	
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name ""
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin); 
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
