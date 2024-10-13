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
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

string s;
int dp[500][500];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	getline(cin, s);

	int n = s.size();

	FOR(i, 0, n) dp[i][i] = 1;
	FORE(len, 2, n) REP(i, n - len + 1) {
		int j = i + len - 1;
		if (len == 2) {
			dp[i][j] = s[i] == s[j] ? 1 : 2;
			continue;
		}
		if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
			dp[i][j] = 1;
			continue;
		}
		dp[i][j] = len;
		FOR(k, i + 1, j) minimize(dp[i][j], dp[i][k] + dp[k + 1][j]);
	}

	cout << dp[0][n - 1];

	return 0;
}
