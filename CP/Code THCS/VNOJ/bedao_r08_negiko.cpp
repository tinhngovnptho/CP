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

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e3 + 11, MOD = 1e9 + 9;

int n, m, k, a[MAXN], b[MAXN];
int64 dp[MAXN][MAXN][11];

void add(int64 &a, int64 b) {
	a += b;
	a %= MOD;
}

void process(void) {
	cin >> n >> m >> k;
	FORE(i, 1, n) cin >> a[i];
	FORE(i, 1, m) cin >> b[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	dp[0][0][0] = 1;
	FORE(i, 0, n) FORE(j, 0, m) FORE(t, 0, k) {
		if (i) add(dp[i][j][t], dp[i - 1][j][t]);
		if (j) add(dp[i][j][t], dp[i][j - 1][t]);
		if (i && j) add(dp[i][j][t], -dp[i - 1][j - 1][t]);
		if (i && j && t && a[i] > b[j]) add(dp[i][j][t], dp[i - 1][j - 1][t - 1]);
	}
	cout << dp[n][m][k];
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("bedao_r08_negiko");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
