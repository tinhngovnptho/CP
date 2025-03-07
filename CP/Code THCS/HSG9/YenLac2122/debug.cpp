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

const int MAXN = 3e5;
int n, a[MAXN], b[MAXN], c[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("debug");
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, n-1) cin >> b[i];
	FOR(i, 0, n-2) cin >> c[i];
	sort(a, a+n);
	sort(b, b+n-1);
	sort(c, c+n-2);
	FOR(i, 0, n) {
		if (i == n || a[i] != b[i]) {
			cout << a[i] << "\n";
			break;
		}
	}
	FOR(i, 0, n-1) {
		if (i == n - 1 || b[i] != c[i]) {
			cout << b[i] << "\n";
			break;
		}
	}

	return 0;
}
