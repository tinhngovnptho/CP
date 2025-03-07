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
const int INF = 1e9 + 11, MAXN = 200 + 11, MOD = 1e9 + 7; 
// const int64_t INFF = (int64_t) 1e18 + 7;
//_______________________________________________________________________________________________

int n, p, h;
int a[MAXN];
ii dp[MAXN][MAXN];

void trace(int i, int j) {
	if (j == 0) return ;
	if (a[i] == 3) {
		if (dp[i - 1][j].se > 1) {
			trace(i - 1, j);
		} else {
			cout << i << " ";
			trace(i, j - 1);
		} 
	} else trace(i - 1, j);
}

void process(void) {
	cin >> n >> p >> h;
	FOR(i, 1, n) cin >> a[i];

	dp[0][0] = {p, h};

	FOR(i, 1, n) {
		int cnt = 0;
		FOR(j, 0, i) {
			if (a[i] == 0) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			if (a[i] == 1) {
				dp[i][j] = dp[i - 1][j];
				dp[i][j].fi++;
			} else if (a[i] == 2) {
				dp[i][j] = dp[i - 1][j];
				dp[i][j].se++;
			} else if (a[i] == 3) {
				if (dp[i - 1][j].se > 1) {
					dp[i][j] = dp[i - 1][j];
					dp[i][j].se--;
				} else if (dp[i - 1][j - 1].fi > 1 && j != 0) {
					dp[i][j] = dp[i - 1][j - 1];
					dp[i][j].fi--;
				} else cnt++;
			}
		}
		if (a[i] == 3 && cnt == i + 1) {
			cout << -1;
			return ;
		}
	}
	int idx = -1;

	FOR(j, 0, n) if (dp[n][j].fi != 0 && dp[n][j].se != 0) {
		idx = j;
		break;
	}

	if (idx == -1) {
		cout << -1;
		return ;
	}

	cout << idx << el;
	trace(n, idx);
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "hero"
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
