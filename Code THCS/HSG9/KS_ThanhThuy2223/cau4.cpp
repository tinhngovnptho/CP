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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	file("nvt");
	int n; cin >> n;
	long long ans = 0;

	FOR(y, 1, n) {
		long long range_x = 1LL * n * n - 1LL * y * y;
		range_x = sqrt(range_x);
		ans += range_x;
	}

	ans = ans * 4LL;

	ans += 4LL * n + 1;

	cout << ans;

	return 0;
}

