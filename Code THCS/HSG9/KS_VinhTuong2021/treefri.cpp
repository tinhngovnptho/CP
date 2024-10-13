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

int x, y, z;

void solve(void) {
	cin >> x >> y >> z;
	for (int i = -1; i <= 1; i += 2) {
		for (int j = -1; j <= 1; j += 2) {
			for (int k = -1; j <= 1; j += 2) {
				if (x * i + y * j + z * k == 0) {
						return void(cout << "yes\n");
				}
			}
		}
	}
	cout << "no\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("treefri");
	int tests; cin >> tests;
	while(tests--) {
		solve();
	}

	return 0;
}
