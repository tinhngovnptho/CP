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

const int MAXN = 1e5 + 11;

char a[MAXN][55];
int n, k, pref[MAXN], cnt[MAXN];
int64 m;

int64 Pow(string s, int64 m, int k) {
	int a = 0;
	REP(i, sz(s)) {
		a = (1LL * a * 10  % k + (s[i] - '0')) % k;
	}
	int res = 1;
	for (; m; m /= 2, a = 1LL * a * a % k)
		if (m & 1) res = 1LL * res * a % k;
	return res;
}

void process(void) {
	cin >> n >> m >> k;
	FORE(i, 1, n) cin >> a[i];
	pref[0] = 0;
	FORE(i, 1, n) {
		pref[i] = (pref[i - 1] + Pow(a[i], m, k)) % k;
	}
	cnt[0] = 1;
	int64 ans = 0;
	FORE(i, 1, n) {
		ans += cnt[pref[i]];
		cnt[pref[i]]++;
	}
	cout << ans;
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("bai5");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
