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

const int MOD =  998244353;

int Pow(int a, int b) {
	int res = 1;
	for (; b; b /= 2, a = 1LL * a * a % MOD) if (b & 1) res = 1LL * res * a % MOD;
	return res;
}

void process(void) {
	string s;
	cin >> s;
	if (sz(s) < 3) return void(cout << 0);
	int res = Pow(26, sz(s) / 2 + 1);
	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("palin");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
