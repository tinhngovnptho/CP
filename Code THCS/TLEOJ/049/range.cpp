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

const int MOD = 1e9;

void process(void) {
	long long L, R; cin >> L >> R;
	vector<long long> f(R - L + 1, 0);
	FORE(i, 1, sqrt(L)) {
		long long v = L / i, u = L / (i + 1);
		f[0] += 1LL * (v - u) * i;
		if (i != L / i) {
			long long j = L / i;
			v = L / j;
			u = L / (j + 1);
			f[0] += 1LL * (v - u) * j;
		}
	}
	f[0] %= MOD;
	vector<long long> cnt(R - L + 1, 0);
	for (long long i = 1; i <= sqrt(R); ++i) {
		for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
			cnt[j - L] += 2;
			if (j == i * i) cnt[j - L]--;
		}
	}
	long long ans = f[0];
	FOR(i, 1, R - L + 1) {
		f[i] = f[i - 1] + cnt[i];
		f[i] %= MOD;
		ans = (ans + f[i]) % MOD;
	}
	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("range");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
