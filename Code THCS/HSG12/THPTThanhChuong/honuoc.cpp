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
	int n, t; cin >> n >> t;
	long long suma = 0, sumb = 0;
	vector<long long> delta(t + 1, 0);
	REP(i, n) {
		int ai, bi; cin >> ai >> bi;
		suma += ai; sumb += bi;
		int T = ai / bi + 1;
		if (T <= t) {
			delta[T] += bi * T - ai;
		}
	}

	cout << suma << "\n";
	FORE(i, 1, t) {
		delta[i] += delta[i - 1];
		cout << suma - sumb * i << " " << delta[i] << ": ";
		cout << suma - sumb * i + delta[i] << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("honuoc");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
