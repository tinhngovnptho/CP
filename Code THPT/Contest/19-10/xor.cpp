/**------------------------------------------
------Author: Tinhnopro (Tinh nop) ----------
---------From: CHV with luv <3 --------------
---------Value = Live + Love ---------------- 
------------------------------------------**/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second

#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define pb push_back

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
const int INF = 1e9 + 11, MAXN = 5e5 + 11, MOD = 1e9 + 7; 
const int64_t INFF = (int64_t) 1e18 + 7;
//_______________________________________________________________________________________________
const int LOG = 40; 

int64_t a, b;
int n, cnt[LOG + 1]; 
int64_t c[MAXN];
int64_t dp[LOG + 1][2][2];

int64_t solve(int id, bool low, bool hight) {
	if (id > LOG || id < 0) return 0;
	int64_t &res = dp[id][low][hight];
	
	if (~res) return res; 

	res = INFF;

	if (low) {
		minimize(res, solve(id - 1, low, hight) + Mask(id) * (n - cnt[id]))
	}
}

void process(void) {
	cin >> n >> a >> b; 
	FOR(i, 1, n) cin >> c[i];

	FORD(bit, LOG, 0) {
		FOR(i, 1, n) cnt[bit] += getbit(bit, c[i]); 
		cout << cnt[bit] << " ";
	}
	cout << el;

	memset(dp, -1, sizeof(dp));

	cout << solve(LOG, 1, 1);
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "xor"
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
