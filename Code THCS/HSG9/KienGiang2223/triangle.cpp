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

int n, a[1000];

bool check_triangle(int a, int b, int c) {
	if (a + b > c && b + c > a && c + a > b) return true;
	return false;
}

long double calc_s(int a, int b, int c) {
	long double res = 0, p = (a + b + c) / 2.0;
	res = 1.0 * p * (p - a) * (p - b) * (p - c);
	res = sqrtl(res);
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("triangle");
	cin >> n;
	REP(i, n) cin >> a[i];

	long double ans = -1;
	int cnt = 0;

	REP(i, n) REP(j, i) REP(k, j) {
		if (check_triangle(a[i], a[j], a[k])) {
//			cout << i << " " << j << " " << k << "\n";
			cnt++;
			maximize(ans, calc_s(a[i], a[j], a[k]));
		}
	}

	cout << cnt << "\n";
	if (ans == -1) cout << -1; else
	cout << fixed << setprecision(2) << ans;

	return 0;
}
