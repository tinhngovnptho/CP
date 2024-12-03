/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-26
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

const int mod = 1e9 + 7;
const int maxN = 1e5 + 11;

using ii = pair<int, int>;

int n, x;
int a[maxN], b[maxN], pos[maxN];
vector<int> arr[maxN];
ii dp[maxN][20];

void fixmod(int &x) {
	if (x < 0) x += mod;
	if (x >= mod) x -= mod;
}

struct FendwickTree {
	ii bit[maxN];
	int sz;

	void update(int u, ii val) {
		for (; u <= sz; u += u & -u)  {
			if (bit[u].first < val.first) {
				bit[u] = val;
			} else if (bit[u].first == val.first) {
				bit[u].second += val.second;
				fixmod(bit[u].second);
			}
		}
	}

	ii get(int u) const {
		ii ret = {0, 1};
		for (; u; u -= u & -u) {
			if (ret.first < bit[u].first) {
				ret = bit[u];
			} else if (ret.first == bit[u].first) {
				ret.second += bit[u].second;
				fixmod(ret.second);
			}
		}
		return ret;
	}
} fendwick;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("lcsxd4.inp", "r", stdin);
	freopen("lcsxd4.out", "w", stdout);
#endif // LOCAL

	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		pos[b[i]] = i;
	}

	for (int i = 1; i <= n; ++i) {
		for (int d = max(a[i] - x, 1); d <= min(n, a[i] + x); ++d) {
			arr[i].push_back(pos[d]);
		}
	}

	int ans = 0, cnt = 0;

	fendwick.sz = n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)arr[i].size(); ++j) {
			ii cur = fendwick.get(arr[i][j] - 1);

			dp[i][j] = cur;
			dp[i][j].first++;

			maximize(ans, dp[i][j].first);
		}
		for (int j = 0; j < (int)arr[i].size(); ++j) {
			fendwick.update(arr[i][j], dp[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)arr[i].size(); ++j) {
			if (ans == dp[i][j].first) {
				cnt += dp[i][j].second;
				fixmod(cnt);
			}
 		}
	}

	cout << ans << ' ' << cnt;
}
