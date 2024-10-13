#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

// end of template

int n;
unsigned long long dp[11][11], sum[11];

void init(void) {
	int n = 10;
	dp[1][1] = 1;
	FORE(i, 2, n) FORE(j, 1, i) {
		dp[i][j] = j * (dp[i-1][j] + dp[i-1][j-1]);
	}
	FORE(i, 1, n) FORE(j, 1, i) {
		sum[i] += dp[i][j];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// 	freopen("nvt.inp", "r", stdin);
// 	freopen("nvt.out", "w", stdout);

	init();
	while(cin >> n && n != -1) {
		cout << sum[n] << "\n";
	}

	return 0;
}
