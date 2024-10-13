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

const int MAX = 5e4 + 11;

int q, MOD, l, r, cnt[MAX];
int maxFactor;

void factor(int x) {
	maximize(maxFactor, x);
	FORE(i, 2, sqrt(x)) if (x % i == 0) {
		int res = 0;
		while (x % i == 0) {
			x /= i;
			res++;
		}
		cnt[i] += res;
	}
	if (x > 1) cnt[x]++;
}

unordered_map<int, int> cnt[MAX];

void init(void) {
	FOR(i, 2, MAX) {
		cnt[i] = cnt[i - 1];
		int x = i;
		FORE(j, 2, sqrt(x)) if (x % j == 0) {
			int res = 0;
			while (x % j == 0) {
				x /= j;
				res++;
			}
			cnt[i][j] += res;
		}
		if (x > 1) cnt[i][x]++;
	}
}

void process(void) {
	cin >> MOD >> q;
	init();
	while (q--) {
		cin >> l >> r;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("j");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
