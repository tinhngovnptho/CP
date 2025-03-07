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
	vector<long long> delta1(t + 1, 0), delta2(t + 1, 0);
	REP(i, n) {
		int ai, bi; cin >> ai >> bi;
		/** Day i = max(0, a1 - b1 * i) + max(0, a2 - b2 * i) + ... + max(0, an - bn * i)
				  = a1 + a2 + .. + an - i (b1 + b2 + ... + bn) - ((ai1 + ai2 + .. + aik) - i (bi1 + ai2 + ... bik))
				  = suma - i * sumb - delta1[i] + i * delta2[i]
			delta[ai / bi + 1] -> delta[t] += ai - i * bi -> update = diff arr
			d[r + 1] = delta[r + 1] - delta[r] -= x
			d[l] += x
		**/
		suma += ai; sumb += bi;
		if (ai / bi + 1 <= t) {
			delta1[ai / bi + 1] += ai;
			delta2[ai / bi + 1] += bi;
		}
	}
	cout << suma << "\n";
	FORE(i, 1, t) {
		delta1[i] += delta1[i - 1];
		delta2[i] += delta2[i - 1];
		cout << suma - i * sumb - delta1[i] + i * delta2[i] <<  "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
