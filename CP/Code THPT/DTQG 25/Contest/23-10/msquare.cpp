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
		template <typename... Args>  
			vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
	};

	template <typename T> struct vec<T, 1> : public vector<T> {
		vec(int n = 0, T val = T()) : vector<T>(n, val) {}
	};
}
using namespace std;

using ii = pair<int, int>;
using db = long double; 

int n, m;
vec<int, 2> v, pref_row, pref_col;

namespace Sub1 {

	bool check(int i, int j, int len) {
		int x = pref_row[i][j + len - 1] - pref_row[i][j - 1];
		int y = pref_col[j][i + len - 1] - pref_col[j][i - 1];
		int a = pref_row[i + len - 1][j + len - 1] - pref_row[i + len - 1][j - 1];
		int b = pref_col[j + len - 1][i + len - 1] - pref_col[j + len - 1][i - 1];
		// cout << len << ": " << x << " " << y << " " << a << " " << b << el; 
		if (min({x, y, a, b}) != max({x, y, a, b})) return false;
		if (x == len) return true;
		return false;
	}

	void solve(void) {
		FORD(len, min(m, n), 1) {
			FOR(i, 1, m - len + 1) {
				FOR(j, 1, n - len + 1) {
					if (i + len - 1 <= m && j + len - 1 <= n) {
						if (check(i, j, len)) {
							cout << 1ll * len * len; 
							return ;
						}
					}	
				}
			}
		}
		cout << 0;
	}
}

void process(void) {
	cin >> m >> n;
	
	pref_row = v = vec<int, 2>(m + 1, n + 1, 0);	
	pref_col = vec<int, 2>(n + 1, m + 1, 0);

	FOR(i, 1, m) FOR(j, 1, n) cin >> v[i][j];

	FOR(i, 1, m) {
		FOR(j, 1, n) pref_row[i][j] = pref_row[i][j - 1] + v[i][j];
	}

	FOR(i, 1, n) {
		FOR(j, 1, m) pref_col[i][j] = pref_col[i][j - 1] + v[j][i];
	}

	return void(Sub1::solve());
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "msquare"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin); 
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
