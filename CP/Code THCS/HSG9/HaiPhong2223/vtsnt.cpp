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

/// Miller rabin by tinhnopro

/**
	x is prime -> a ^ (x - 1) mod x = 1
	-> a ^ 2^k*m - 1 mod x = 0
	-> a^m mod x = 1 or 0 <= l < k -> (a^m)^2^l mod x = x - 1
**/

int Pow(int a, int b, int mod) {
	int res = 1;
	for (; b; b /= 2, a = 1LL * a * a % mod) if (b & 1) res = 1LL * res * a % mod;
	return res;
}

bool MillerTest(int a, int k, int m, int x) {
	int p = Pow(a, m, x);
	if (p == 1) return true;
	while (k--) {
		if (p == x - 1) return true;
		p = 1LL * p * p % x;
	}
	return false;
}

bool isPrime(int x) {
	 if (x <= 3) return x > 1;
	 if (x % 2 == 0 || x % 3 == 0) return false;
	 int m = x - 1, k = 0;
	 while (m % 2 == 0) {
		m /= 2;
		k++;
	 }
	 for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}) {
		if (x == a) return true;
		if (!MillerTest(a, k, m, x)) return false;
	 }
	 return true;
}

void process(void) {
	int n; cin >> n;
	vector<int> v;
	REP(i, n) {
		int x; cin >> x;
		if (isPrime(x)) v.push_back(i + 1);
	}
	if (sz(v) == 0) return void(cout << -1);
	REP(i, sz(v )) cout << v[i] << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("vtsnt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
