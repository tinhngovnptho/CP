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

int n, k, x, y, a[MAXN], b[MAXN];

void process(void) {
	cin >> n >> k >> x >> y;
	FORE(i, 1, n) {
		cin >> a[i];
	}
	FORE(i, 1, n) {
		cin >> b[i];
	}
	if (k == 0) return void(cout << a[x] + b[y]);
	if (k == 1) {
		int ans = a[x] + b[y];
		if (x - 1 > 0) maximize(ans, a[x - 1] + b[y]);
		if (x + 1 <= n) maximize(ans, a[x + 1] + b[y]);
		if (y - 1 > 0) maximize(ans, a[x] + b[y - 1]);
		if (y + 1 <= n) maximize(ans, a[x] + b[y + 1]);
		return void(cout << ans);
	}
	int ans = a[x] + b[y];
	FORE(u, 0, min(k, n)) {
		int v = k - u, amax = a[x], bmax = b[y];
		if (x - u > 0) maximize(amax, a[x - u]);
		if (x + u <= n) maximize(amax, a[x + u]);
		if (y - v > 0) maximize(bmax, b[y - v]);
		if (y + v <= n) maximize(bmax, b[y + v]);
		maximize(ans, amax + bmax);
	}
	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("l");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
