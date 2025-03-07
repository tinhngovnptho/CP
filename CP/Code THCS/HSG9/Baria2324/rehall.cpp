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

const int MAXN = 1e5 + 5;

int n, dp[MAXN];
vector<pair<int, int> > t[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("rehall");
	cin >> n;
	REP(i, n) {
		int l, r, c;
		cin >> l >> r >> c;
		t[r].push_back(make_pair(l, c));
	}

	dp[0] = 0;

	FOR(i, 1, MAXN) {
		dp[i] = dp[i- 1];
		REP(j, sz(t[i])) {
			maximize(dp[i], dp[t[i][j].fi - 1] + t[i][j].se);
		}
	}

	cout << dp[MAXN-1];

	return 0;
}
