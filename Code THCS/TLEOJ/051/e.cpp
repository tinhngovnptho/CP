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

const int MAXN = 1e6 + 11;

int k, s[4][MAXN];
long long dp[MAXN][4];

void process(void) {
	cin >> k;
	FORE(i, 1, 3) FORE(j, 1, k) cin >> s[i][j];
	FORE(j, 1, 3) dp[1][j] = s[j][1];
	FORE(i, 2, k) {
		dp[i][1] = max(dp[i - 1][2] + s[1][i], dp[i - 1][3] - s[1][i]);
		dp[i][2] = max(dp[i - 1][1] - s[2][i], dp[i - 1][3] + s[2][i]);
		dp[i][3] = max(dp[i - 1][1] + s[3][i], dp[i - 1][2] - s[3][i]);
	}
	cout << *max_element(dp[k] + 1, dp[k] + 3);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("e");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
