// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MOD = 998244353, MAXN = 1e4 + 11, MAX = 200;

int n, p, x, a[MAXN], dp[MAXN][MAX];

void add(int &a, int b) {
	int c = a + b;
	a = c % MOD;
}

void process(void) {
	cin >> n >> p >> x;
	FORE(i, 1, n) {
		cin >> a[i];
		a[i] %= x;
	}
	FORE(i, 1, n) {
		dp[i][a[i]] = 1;
		FOR(j, 0, x) {
			add(dp[i][j], dp[i - 1][j]);
			FOR(k, 0, i) add(dp[i][j], dp[k][(j - a[i] + x * x) % x]);
		}
	}
	int res = 0;
	FORE(i, 1, n) add(res, dp[i][p]);
	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("modsum");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
