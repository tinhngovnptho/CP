/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-28
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

template <typename T> inline int isize(const T& a) { return a.size(); }

template <typename T1, typename T2> bool maximize(T1& a, T2 b) { return a < b ? a = b, true : false; }
template <typename T1, typename T2> bool minimize(T1& a, T2 b) { return a > b ? a = b, true : false; }

constexpr int maxN = 4e5 + 11;
constexpr int64_t inf = (int64_t) 1e18 + 11;

int n, r;
int64_t a[maxN], dp[maxN][2];

void solve() {
	cin >> n >> r;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n + r; ++i) {
		a[i] += a[i - 1];
		dp[i][0] = dp[i][1] = -inf;
	}

	int64_t ans = -inf;

	dp[0][0] = 0;
	dp[0][1] = -inf;

	for (int i = 1; i <= n + r; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		maximize(dp[i][1], dp[i - 1][1] + a[i] - a[i - 1]);
		int d = max(0, i - 2 * r - 1);
		if (i > r) {
			maximize(dp[i][1], dp[d][0] + a[i] - a[d]);
		}
		maximize(ans, dp[i][1]);
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("bowling.inp", "r", stdin);
	freopen("bowling.out", "w", stdout);
#endif // LOCAL

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
}
