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

void process(void) {
	long long n, a, b; cin >> a >> b >> n;
	if (a >= b) {
		return void(cout << (a == b ? "Yes" : "No") << "\n");
	}
	if (b % n != 0) {
		return void(cout << ((b - a) % n == 0 ? "Yes" : "No") << "\n");
	}
	a %= n;
	if (a == 0 || a == 1) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("transform");
	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
