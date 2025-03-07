  /*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif

using namespace std;

const int MOD = 123456789;

int n, k, m;

namespace Sub1 {
	const int MAXN = 3011;

	int64_t dp[MAXN][MAXN];

	int call(int i){
		int l = 1;

		while (((l - i) % m != 0 || l % 2 == 0) && l <= 300)
			l ++;

		if ((l - i) % m != 0)
			return 0;

		int r = k;
		while (((r - i) % m != 0 || r % 2 == 0) && k - r <= 300)
			r --;

		if ((r - i) % m != 0)
			return 0;

		int dist = m * 2;

		if ((l + m) % 2 == 1)
			dist = m;

		return (r - l) / dist + 1;
	}

	int calc(int i){
		int l = 1;

		while (((l - i) % m != 0 || l & 1) && l <= 200 && l <= k)
			l ++;

		if ((l - i) % m != 0 || l > k || l & 1)
			return 0;

		int r = k;
		while (((r - i) % m != 0 || r & 1) && k - r <= 200 && r > 0)
			r --;

		if ((r - i) % m != 0 || r < 1 || r & 1)
			return 0;

		int dist = m * 2;

		if ((l + m) % 2 == 0)
			dist = m;

		if (r < l)
			return 0;

		return (r - l) / dist + 1;
	}

	void solve(void) {
		for (int i = 0; i < m; ++i) {
			dp[1][i] = call(i);
			dp[1][i] %= MOD;
		}

		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int d = 0; d < m; ++d) {
					int add = (i % 2 ? call(d) : calc(d));
					dp[i][(j + d) % m] += 1LL * add * (dp[i - 1][j]) % MOD;
					dp[i][(j + d) % m] %= MOD;
				}
			}
		}
		cout << dp[n][0];
	}
}

void run_case(void) {
	cin >> n >> k >> m;

	if (n % 4 == 0 || n % 4 == 3) {
		if (m % 2 == 1) {
			cout << 0;
			return;
		}
	} else if (m % 2 == 0) {
		cout << 0;
		return;
	}

	Sub1::solve();
}

int32_t main(void) {
	cin.tie(0)->sync_with_stdio(0);

	if (fopen("cards.inp", "r"))
		assert(freopen("cards.inp", "r", stdin)), assert(freopen("cards.out", "w", stdout));


	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		run_case();
	}
//	cerr << "\nExecution time : " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms] Tinhnop";
}
