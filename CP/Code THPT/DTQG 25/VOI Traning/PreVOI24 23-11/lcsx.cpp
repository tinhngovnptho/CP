/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-23
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#if __cplusplus < 202002L
template <class T> int ssize(const T &a) { return a.size(); }
#endif // __cplusplus

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

using int64 = long long;

const int maxN = 1e5 + 11;
const int mod = 1e9 + 7;

int n, x;
int a[maxN], b[maxN];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

namespace Sub123 {

	bool check() {
		return n <= 2000;
	}

	int dp[2011][2011], cnt[2011][2011];

	void solve() {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (dp[i][j] == dp[i - 1][j]) {
					cnt[i][j] = cnt[i - 1][j];
				} else cnt[i][j] = cnt[i][j - 1];
				if (dp[i - 1][j] == dp[i][j - 1]) {
					add(cnt[i][j], cnt[i - 1][j]);
				}
				if (abs(a[i] - b[j]) <= x) {
						if (maximize(dp[i][j], dp[i - 1][j - 1] + 1)) {
							cnt[i][j] = 1;
						} else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
							add(cnt[i][j], cnt[i - 1][j - 1]);
						}
				}
			}
		}
		cout << dp[n][n] << ' ' << cnt[n][n];
	}
}

namespace Sub4 {

	int posB[maxN], arr[maxN];
	pair<int, int> bit[maxN], dp[maxN];

	void update(int u, pair<int, int> val) {
		for (; u <= n; u += u & -u) {
			if (bit[u].first < val.first) {
				bit[u] = val;
			} else if (bit[u].first == val.first) {
				add(bit[u].second, val.second);
			}
		}
	}

	pair<int, int> Get(int u) {
		pair<int, int> ans = {0, 1};
		for (; u; u -= u & -u) {
			if (ans.first < bit[u].first) {
				ans = bit[u];
			} else if (ans.first == bit[u].first) {
				add(ans.second, bit[u].second);
			}
		}
		return ans;
	}

	void solve() {
		for (int sign : {1, -1}) {
		for (int d = 0; d <= x; ++d) {
			for (int i = 1; i <= n; ++i) posB[b[i]] = i;
			for (int i = 1; i <= n; ++i) arr[i] = posB[min(n, max(1, a[i] + sign * d))];

			for (int i = 1; i <= n; ++i) {
				dp[i] = Get(arr[i] - 1);
				dp[i].first++;
				update(arr[i], dp[i]);
			}
		}
		}

		cout << Get(n).first << ' ' << Get(n).second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("lcsx.inp", "r", stdin);
//	freopen("lcsx.out", "w", stdout);

	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}

	return Sub4::solve(), 0;
}
