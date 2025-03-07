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

int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}

void process(void) {
	string a, b; cin >> a >> b;
	int l = lcm(sz(a), sz(b));
	int d1 = l / sz(a), d2 = l / sz(b);
	string res1, res2;
	while (d1) {
		res1 += a;
		d1--;
	}

	while (d2) {
		res2 += b;
		d2--;
	}

	cout << (res1 == res2 ? res1 : "-1") << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
