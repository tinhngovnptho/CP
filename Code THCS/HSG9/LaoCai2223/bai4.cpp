#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
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

const int MAXN = 1e6 + 11;

int n, k, a[MAXN];
bool prime[MAXN];

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	for (int i = 2; i * i <= n; ++i) if (prime[i]) {
		FORE(j, i, n / i) prime[i * j] = 0;
	}
}

void process(void) {
	cin >> n >> k;
	FORE(i, 1, n) cin >> a[i];
	sieve(MAXN - 1);
	int cnt = 0;
	FORE(i, 1, k) if (prime[a[i]]) cnt++;
	int res = 0, ans = 0;
	FORE(i, 2, k + 1) {
		if (prime[a[i - 1]]) cnt--;
		if (prime[a[i + k - 1]]) cnt++;
		if (maximize(res, cnt)) {
			ans = i;
		}
	}
	cout << ans << " " << ans + k - 1;
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("bai4");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
