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
	file("nvt");
	pair<int, int> x, y, u, v;
	cin >> x.fi >> y.fi >> x.se >> y.se >> u.fi >> v.fi >> u.se >> v.se;

	pair<int, int> dx, dy;

	dx.fi = max(x.fi, u.fi);
	dx.se = min(x.se, u.se);
	dy.fi = max(y.fi, v.fi);
	dy.se = min(y.se, v.se);

	long long S = 1LL * max(0, dx.se - dx.fi) * max(0, dy.se - dy.fi);

	cout << S;

	return 0;
}
