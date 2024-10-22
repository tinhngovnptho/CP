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
const int INF = 1e9 + 11, MAXN = 1e7 + 11, MOD = 1e9 + 7; 
// const long long INFF = (long long) 1e18 + 7;
//_______________________________________________________________________________________________

long long dp[20][9 * 15];
int d[20];
bool prime[1111];
int cnt[MAXN];

int sum_digt(long long x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res; 
}

void preprocess(void) {
	FOR(i, -0, 1000) prime[i] = true;
	prime[0] = prime[1] = false;
	FOR(i, 2, sqrt(1000)) if (prime[i]) for (int j = i * i; j <= 1000; j += i) {
		prime[j] = false;
	}

	FOR(i, 1, 1e7) {
		cnt[i] = cnt[i - 1];
		if (prime[sum_digt(1ll * i * i)]) {
			cnt[i]++;  
		}
	}

	memset(dp, -1, sizeof(dp));
} 

int64_t calc(int id, int sum, bool low) {
	if (id < 0) {
		return prime[sum];
	}

	if (low && ~dp[id][sum]) return dp[id][sum];

	int max_digt = low ? 9 : d[id];
	int64_t cur = 0;
	FOR(c, 0, max_digt) {
		cur += calc(id - 1, sum + c, low || (c < max_digt));
	}

	if (low) dp[id][sum] = cur;
	return cur;
}

long long solve(long long x) {
	int i = 0;
	int l = trunc(sqrt(x));
	while (x) {
		d[i] = x % 10;
		x /= 10;
		i++;
	}
	return calc(i - 1, 0, false) - cnt[l];
}

long long a, b; 

void process(void) {
	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << el;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "spnum"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin); 
		freopen(name".out", "w", stdout);
	}
	//____________________________________________________
	preprocess();
	int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
