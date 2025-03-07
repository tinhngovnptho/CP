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

typedef pair<int, int> pii;

const int MAXN = 1e5 + 11;

int n, dp[MAXN];
pii a[MAXN];

bool cmp_seg(const pii &a, const pii &b) {
	if (a.se == b.fi) return a.fi < b.fi;
	return a.se < b.fi;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	cin >> n;
	REP(i, n) {
		cin >> a[i].fi >> a[i].se;
	}
	sort(a, a + n);

	REP(i, n) cout << a[i].fi << " " << a[i].se << "\n";

	REP(i, n) dp[i] = 1;
	REP(i, n) REP(j, i) if (a[i].fi >= a[j].se) {
		maximize(dp[i], dp[j] + 1);
	}

	cout << n - dp[n - 1];

	return 0;
}
