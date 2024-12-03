/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

int64_t n;

namespace Sub2 {
	const int FIX = 60;

	int64_t dp[63][125][2], a[63];

	int64_t calc(int i, int sum, int last, bool tight, bool check) {
		if (i < 0) {
			if (check && sum - FIX == 0) {
				return 1;
			}
			return 0;
		}
		if (!tight && check && ~dp[i][sum][last]) return dp[i][sum][last];
		int max_digt = tight ? a[i] : 1;
		int64_t cur = 0;
		for (int c = 0; c <= max_digt; ++c) {
			int new_sum = sum; 
			if (check) new_sum += (c == last ? 1 : -1);
			cur += calc(i - 1, new_sum, c, tight && (c == max_digt), check || (c == 1));
		}
		if (!tight && check) dp[i][sum][last] = cur;
		return cur;
	}

	int64_t solve_dp(int64_t x) {
		for (int i = 61; i >= 0; --i) { 
			a[i] = (x >> i) & 1LL;
		}
		return calc(61, FIX, 0, true, false);
	}

	void solve(void) {
		memset(dp, -1, sizeof(dp));
		cout << solve_dp(n);
	}
}

void run_case(void) {
	cin >> n;
	Sub2::solve();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// freopen("sfunc.inp", "r", stdin);
	// freopen("sfunc.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
}
