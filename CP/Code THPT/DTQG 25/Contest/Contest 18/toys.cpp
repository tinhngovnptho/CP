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
const int MAXN = 1e6 + 11;
const int MOD = 1e9 + 7;
//_______________________________________________________________________________________________

int n, m;
int v[MAXN], sos[1 << 20 + 1];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void dec(int &a, int b) {
	a -= b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
}

int pow2(int b) {
	int res = 1;
	int a = 2; 
	for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) {
		res = 1LL * res * a % MOD; 
	}
	return res;
}

void process(void) {
	cin >> n >> m;

	FOR(i, 1, n) {
		int k; cin >> k;
		FOR(j, 1, k) {
			int x; cin >> x;
			v[i] = onbit(x - 1, v[i]);
		}
		// cout << v[i] << el;
		sos[v[i]]++;
	}

	FOR(i, 0, m - 1)  FOR(mask, 0, Mask(m) - 1) if (getbit(i, mask)) {
		sos[mask] += sos[mask ^ Mask(i)]; 
	}

	int ans = 0;
	FOR(i, 0, Mask(m) - 1) {
		int c = cntbit(i);
		if (c & 1) add(ans, pow2(sos[i]));
		else dec(ans, pow2(sos[i]));
	}

	if (m & 1) cout << ans;
	else cout << (-ans + MOD) % MOD;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "toys"
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
