#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;
typedef __int128_t int128;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 2e5 + 11;

int q;
int64 l[MAXN], r[MAXN];

int sumDigt(int64 x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int calc(int64 x) {
	int res = 0;
	FORE(i, 0, 9 * 18) {
		if (x >= i && sumDigt(x - i) == i) res++;
	}
	return res;
}

namespace SubR {
	bool check(void) {
		FORE(i, 1, q) if (r[i] > 1e3) return false;
		return true;
	}
	int calc(int64 x) {
		int res = 0;
		FORE(i, 0, 9 * 6) {
			if (x >= i && sumDigt(x - i) == i) res++;
		}
		return res;
	}
	const int MAX = 1e3 + 3;
	int64 f[MAX];
	void solve(void) {
		FOR(i, 1, MAX) f[i] = f[i - 1] + calc(i);
		FORE(i, 1, q) cout << f[r[i]] - f[l[i] - 1] << "\n";
	}
};

void process(void) {
	cin >> q;
	FORE(i, 1, q) cin >> l[i] >> r[i];
	if (SubR::check()) return SubR::solve();
	FORE(i, 1, q) {
		int64 L = l[i], R = r[i], ans = 0;
		for (int64 j = L; j <= R; ++j) ans += calc(j);
		cout << ans << "\n";
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("gennum");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
