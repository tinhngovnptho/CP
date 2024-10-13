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

const int MAXN = 1e3 + 11, MAXV = 1e4 + 11;

int n, v, h[MAXN], t[MAXN], dp[MAXN][MAXV];

void process(void) {
	cin >> n >> v;
	FORE(i, 1, n) cin >> h[i];
	FORE(i, 1, n) cin >> t[i];

	/// dp[i][j] la tong do hung du neu xet i ten cuop dau va co j dong tien
	/// dp[i][j] = max(dp[i - 1][j] , dp[i-1][j - t[i]] + h[i])

	memset(dp, -1, sizeof dp);
	FORE(j, t[1], v) dp[1][j] = h[1];
	FORE(i, 2, n) FORE(j, 1, v) {
		if (dp[i - 1][j] >= h[i]) dp[i][j] = dp[i - 1][j];
		if (dp[i - 1][j - t[i]] != -1) maximize(dp[i][j], dp[i - 1][j - t[i]] + h[i]);
	}
//
//	FORE(i, 1, n) {
//		FORE(j, 0, v) cout << dp[i][j] << " ";
//		cout << "\n";
//	}

	FORE(j, 0, v) if (dp[n][j] != -1) {
		return void(cout << j);
	}
	cout << -1;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
