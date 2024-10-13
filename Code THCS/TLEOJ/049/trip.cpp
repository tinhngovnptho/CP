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

const int MAXN = 2e5 + 11;

int n, l[MAXN], r[MAXN];

void process(void) {
	cin >> n;
	FOR(i, 1, n) cin >> l[i];
	FOR(i, 1, n) cin >> r[i];
	memset(dp, 0, sizeof dp);
	dp[1] = 1;
	FOR(i, 1, n) {
		FORE(j, l[i], r[i]) maximize(dp[j], dp[i] + 1);
	}
//		FORE(i, 1, n) cout << dp[i] << " ";
	cout << dp[n];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("trip");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
