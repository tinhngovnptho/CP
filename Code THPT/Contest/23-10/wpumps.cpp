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

const int MOD = 1e9 + 7; 
const int MAXN = 3111;

int n, m, a[MAXN];

void process(void) {
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	cin >> m;

	a[0] = 0;

	FOR(nvt, 1, m) {
		FOR(i, 1, n) {
			a[i] += a[i - 1];
			if (a[i] >= MOD) a[i] -= MOD;
		}
	}
	FOR(i, 1, n) cout << a[i] << " ";
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "wpumps"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin); 
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
