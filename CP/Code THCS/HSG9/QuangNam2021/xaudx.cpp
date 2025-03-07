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

int dp[2001][2001];

void process(void) {
	string s; getline(cin, s);
	int n = s.size(); s = " " + s;
	/**
		f(i, j) = 1 || 0 -> s[i..j] is palin
		f(i, i) = 1
		f(i, i + 1) = s[i] == s[j]
		f(i, j) = f(i + 1, j - 1) && s[i] == s[j]
	**/
	int ans = 1;
	FORE(len, 1, n) FORE(i, 1, n - len + 1) {
		if (len == 1) {
			dp[i][i] = 1;
			continue;
		}
		if (len == 2) {
			dp[i][i + 1] = s[i] == s[i + 1];
			continue;
		}
		int j = i + len - 1;
		if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
		if (dp[i][j]) {
			maximize(ans, len);
		}
	}
	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("xaudx");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
