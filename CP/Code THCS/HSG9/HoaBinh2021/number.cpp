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

const long long INF = 1e18 + 11;

long long calc(long long a, long long b) {
	if (a == 0) return 0;
	if (b == 1) return INF;
	long long res = 0;
	while (a) {
		a /= b;
		res++;
	}
	return res;
}

void process(void) {
	long long a, b; cin >> a >> b;
	long long ans = INF;
	for (int i = 0; ; ++i) {
		long long x = calc(a, b + i) + i;
		if (x > ans) break;
		ans = x;
	}
	cout << ans << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
