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

const int MAX = 1e4 + 11;

int q;
long long queries[MAX];

namespace Sub1 {
	bool check(void) {
		FORE(i, 1, q) if (queries[i] > 1e6) return false;
		return true;
	}
	const int MAXN = 1e6 + 11;
	int cntDiv[MAXN + 1];
	void solve(void) {
		FORE(i, 2, MAXN) cntDiv[i] = i + 1;
		cntDiv[0] = 0; cntDiv[1] = 1;
		FORE(i, 2, sqrt(MAXN)) {
			FORE(j, i, MAXN / i) cntDiv[i * j] += i + j;
			cntDiv[i * i] -= i;
		}
		FORE(i, 1, q)
			if (cntDiv[queries[i]] - queries[i] > sqrt(queries[i]))
				cout << "YES\n";
			else
				cout << "NO\n";
	}
};

namespace Sub2 {
	long long mul(long long a, long long b, long long mod) {
		a %= mod;
		long long res = 0;
		for (; b; b /= 2,a = 2 * a % mod) if (b & 1) res = (res + a) % mod;
		return res;
	}
	long long Pow(long long a, long long b, long long mod) {
		long long res = 1;
		for (; b; b /= 2, a = mul(a, a, mod)) if (b & 1) res = mul(res, a, mod);
		return res;
	}

	bool MillerTest(long long a, long long k, long long m, long long x) {
		long long p = Pow(a, m, x);
		if (p == 1) return true;
		while (k--) {
			if (p == x - 1) return true;
			p = mul(p, p, x);
		}
		return false;
	}

	bool isPrime(long long x) {
		if (x <= 3) return x > 1;
		if (x % 2 == 0 || x % 3 == 0) return false;
		long long m = x - 1, k = 0;
		while (m % 2 == 0) {
			m /= 2;
			k++;
		}
		for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}) {
			if (x == a) return true;
			if (!MillerTest(a, k, m, x)) return false;
		}
		return true;
	}

	void solve(void) {
		FORE(i, 1, q) {
			if (queries[i] < 2) {
				cout << "NO\n";
				continue;
			}
			cout << (isPrime(queries[i]) ? "NO" : "YES") << "\n";
		}
	}
};

void process(void) {
	cin >> q;
	FORE(i, 1, q) cin >> queries[i];
	if (Sub1::check()) return void(Sub1::solve());
	Sub2::solve();
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("sodocla");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
