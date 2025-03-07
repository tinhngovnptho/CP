#include <bits/stdc++.h>

#define TASK "cc"

using namespace std;

const int maxN = 5e5 + 11;
const int64_t inf = (int64_t) 1e18 + 5;

int n;
int64_t c[maxN], a[maxN], dp[maxN];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	for (int i = 1; i < n; ++i) {
		cin >> a[i];
	}

	dp[0] = dp[n] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = a[i];
		int64_t mxc = -1, cur = inf;
		for (int j = i - 1; ~j; --j) {
			mxc = max(mxc, c[j]);
			cur = min(cur, dp[j] + mxc * (i - j));
		}
		dp[i] += cur;
	}

	cout << dp[n];
}
