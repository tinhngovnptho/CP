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

const int MOD = 1234567891, MAXN = 1e6 + 11;
int a[MAXN], b[MAXN], n;

void process(void) {
	cin >> n;
	FORE(i, 1, n) cin >> a[i];
	FORE(i, 1, n) cin >> b[i];
	long long cnt = 0;
	FORE(l1, 1, n) FORE(r1, l1, n) FORE(l2, 1, n) FORE(r2, l2, n) {
		long long max_a = 0, min_b = 1e18 + 11;
		FORE(i, l1, r1) maximize(max_a, a[i]);
		FORE(i, l2, r2) minimize(min_b, b[i]);
		if (max_a == min_b) cnt++;
	}
	cout << cnt % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("mmb");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
