/**------------------------------------------
------Author: Tinhnopro (Tinh nop) ----------
---------From: CHV with luv <3 --------------
---------Value = Live + Love ----------------
------------------------------------------**/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second
#define eb emplace_back

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()

#define Mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | Mask(i))
#define offbit(i, mask) (mask & ~(Mask(i)))
#define cntbit(x) __builtin_popcountll(x)
#define Log2(x) (63 - __builtin_clzll(x))

using namespace std;

using db = long double;
using vi = vector<int>;
using ii = pair<int, int>;
using ii64 = pair<int64_t, int64_t>;

template<class X, class Y> bool maximize(X &a, Y b) {
	return a < b ? a = b, 1 : 0;
}

template<class X, class Y> bool minimize(X &a, Y b) {
	return a > b ? a = b, 1 : 0;
}

template<class X, class Y> void modmize(X &a, const Y &b) {
	if (a >= b) a -= b;
}

template<class T> using vector2d = vector<vector<T>>;

// const int dx[8] = {+1, -1, +0, +0, +1, -1, +1, -1}, dy[8] = {+0, +0, +1, -1, +1, -1, -1, +1};
// const int INF = 1e9 + 11, LOG = 25, BLOCK = 700, MAXN = 5e5 + 11, MAX = 1e6 + 11;
// const int64_t INFF = (int64_t) 1e18 + 7, BASE = 311, MOD = 1e9 + 7;
//_______________________________________________________________________________________________


void process(void) {

}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	#define name "centroid_c"
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
