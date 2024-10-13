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

int sum(string a, string b) {
//	assert(a.size() == 2 && b.size() == 2);
	int sum1 = 0, sum2 = 0;
	FOR(i, 0, sz(a)) sum1 = sum1 * 10 + (a[i] - '0');
	FOR(i, 0, sz(b)) sum2 = sum2 * 10 + (b[i] - '0');
	return sum1 + sum2;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("swapdigt");
	int tests; cin >> tests;
	while(tests--) {
		string a, b; cin >> a >> b;
		int n = sum(a, b);
		FOR(i, 0, sz(a)) {
			FOR(j, 0, sz(b)) {
				swap(a[i], b[j]);
				maximize(n, sum(a, b));
				swap(a[i], b[j]);
			}
		}
		cout << n << "\n";
	}

	return 0;
}
