/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-18
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#define ssz(s) ((int) (s).size())
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;
typedef unsigned long long uint64;
////////////////////////////////////////

const int maxN = 3e5 + 11;

int n, k, a[maxN];
pair<int64, int> dp[maxN][2];

pair<int64, int> alien_dp(int64 pen) {
	for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = {0, 0};
	dp[1][0] = {0, 0};
	dp[1][1] = {a[1] - pen, 1};
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

		dp[i][1] = max(make_pair(dp[i - 1][0].first + a[i] - pen, dp[i - 1][0].second + 1),
						make_pair(dp[i - 1][1].first + a[i], dp[i - 1][1].second));

	}
	return max(dp[n][0], dp[n][1]);
}

void tinhnop() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int64 lo = 0, hi = 1e18, res = 0;
	while (lo <= hi) {
		int64 mid = (lo + hi) >> 1;
		if (alien_dp(mid).second >= k) {
			res = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}

	cout << alien_dp(res).first + 1LL * k * res;
}
////////////////////////////////////////
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("BANQUET.inp", "r", stdin);
	freopen("BANQUET.out", "w", stdout);
///////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
