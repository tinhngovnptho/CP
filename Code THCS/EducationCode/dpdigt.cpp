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

const int MAX_DIGT = 81 * 81;

bool prime[MAX_DIGT + 1];
int a[18];
long long dp[18][MAX_DIGT];

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	prime[0] = prime[1] = 0;
	FORE(i, 2, sqrt(n)) if (prime[i]) FORE(j, i, n / i) prime[i * j] = 0;
}

long long calc_dp(int i, bool tight, int sum) {
	if (i < 0) {
		if (prime[sum]) return 1;
		else return 0;
	}
	if (!tight && dp[i][sum] >= 0) return dp[i][sum];
	long long res = 0;
	int maxc = (tight ? a[i] : 9);
	REP(i, maxc + 1) {
		bool new_tight = tight && (i == maxc);
		res += calc_dp(i - 1, new_tight, sum + i * i);
	}
	if (!tight) dp[i][sum] = res;
	return res;
}

long long calc(long long x) {
	int n = 0;
	while (x) {
		a[n] = x % 10;
		x /= 10;
		n++;
	}
	return calc_dp(n - 1, true, 0);
}

void process(void) {
	long long a, b; cin >> a >> b;
	sieve(MAX_DIGT);
	memset(dp, -1, sizeof dp);
	cout << "ok" << "\n";
	cout << calc(b) - calc(a - 1);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
