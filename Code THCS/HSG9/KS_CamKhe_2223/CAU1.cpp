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

int d, m, y;

void solve(void) {
	int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	cin >> d >> m >> y;

	if (m > 12) {
		cout << "KHONG\n";
		return ;
	}
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) days_of_month[1]++;
	if (d > days_of_month[m - 1]) cout << "KHONG\n";
	else cout << "CO\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("cau1");

	int tests; cin >> tests;
	while (tests--) solve();

	return 0;
}
