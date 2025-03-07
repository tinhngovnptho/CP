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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	int m; cin >> m;

	if (m == 0) {
		cout << 10;
		exit(0);
	}

	if (m == 1) {
		cout << 11;
		exit(0);
	}

	string res;
	FORDE(i, 9, 2) if (m % i == 0) {
		while (m % i == 0) {
			m /= i;
			res = char(i + '0') + res;
		}
	}

	if (sz(res) == 1) res = "1" + res;

	if (m != 1) {
		cout << -1;
	} else {
		cout << res;
	}

	return 0;
}
