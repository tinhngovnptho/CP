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

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
	static_assert(D >= 1, "Init Error");
	template <typename... Args>
	vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};

template <typename T>
struct vec<T, 1> : public vector<T> {
	vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};

const int DIRX[4] = {1, 0, -1, 0};
const int DIRY[4] = {0, 1, 0, -1};

int m, n;

int calc(vec<int, 2>& dp, const vec<int, 2>& a, int i, int j) {
	if (~dp[i][j]) return dp[i][j];

	int cur = 0;
	for (int k = 0; k < 4; ++k) {
		int adj_i = i + DIRX[k];
		int adj_j = j + DIRY[k];
		if (adj_i < 0 || adj_i > m) continue;
		if (adj_j < 0 || adj_j > n) continue;
		if (a[i][j] >= a[adj_i][adj_j]) continue;
		maximize(cur, calc(dp, a, adj_i, adj_j));
	}

	return dp[i][j] = cur + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("LISTAB.inp", "r", stdin);
	freopen("LISTAB.out", "w", stdout);
#endif // LOCAL

	cin >> m >> n;

	vec<int, 2> a(m + 2, n + 2, 0), dp(m + 2, n + 2, -1);

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			maximize(ans, calc(dp, a, i, j));
		}
	}

	cout << ans;
}
