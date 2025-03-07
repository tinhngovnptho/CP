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
const int INF = 1e9 + 11, MAXN = 500, MOD = 1e9 + 7; 
// const int64_t INFF = (int64_t) 1e18 + 7;
//_______________________________________________________________________________________________
const int FIX = 101;

int m, d[MAXN][MAXN];
ii A[MAXN][22];

bool cmp(const ii &a, const ii &b) {
	if (a.fi == b.fi) {
		return a.se < b.se;
	}
	return a.fi < b.fi;
}

void updateRange(ii a, ii b) {
	a.fi += FIX;
	a.se += FIX;
	b.fi += FIX;
	b.se += FIX;
	int h = a.se - b.se;
	int w = a.fi - b.fi;
	// cout << a.fi << " " << a.se << el;
	// cout << b.fi << " " << b.se << el;
	FOR(i, b.fi + 1, b.fi + w) {
		FOR(j, b.se + 1, b.se + h) {
			d[i][j] = 1; 
		}
	}
}

void process(void) {
	cin >> m;
	FOR(i, 1, m) {
		int n; cin >> n;
		assert(n == 4);
		FOR(j, 1, n) cin >> A[i][j].fi >> A[i][j].se; 
		sort(A[i] + 1, A[i] + n + 1);
		// FOR(j, 1, n) cout << A[i][j].fi << " " << A[i][j].se << el;
		updateRange(A[i][n], A[i][1]);
	}
	int res = 0;
	FOR(i, 1, 300) FOR(j, 1, 300) if (d[i][j]) {
		// cout << i - FIX << " " << j - FIX << el;
		res++;
	}
	cout << res;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "poly"
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
