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

const int maxN = 2e5 + 11;
const int inf = 1e9 + 11;

int n, a[maxN];
int dp[2009][2009];

int calc(int l, int r) {
	if (l == 1 && r == 2 * n + 1) return 0;
	if (~dp[l][r]) return dp[l][r];

	int cur = inf;
	if (l != 1 && a[l] == a[l - 1]) minimize(cur, calc(l - 1, r));
	if (r != 2 * n + 1 && a[r] == a[r + 1])  minimize(cur, calc(l, r + 1));
	if (l != 1 && a[l] != a[l - 1]) minimize(cur, calc(l - 1, r) + 1);
	if (r != 2 * n + 1 && a[r] != a[r + 1]) minimize(cur, calc(l, r + 1) + 1);
	if (l != 1 && r != 2 * n + 1 && a[l - 1] == a[r + 1] && a[l] != a[l - 1] && a[r] != a[r + 1])
		minimize(cur, calc(l - 1, r + 1) + 1);

	return dp[l][r] = cur;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("robotv4.inp", "r", stdin);
	freopen("robotv4.ans", "w", stdout);
#endif // LOCAL

	cin >> n;
	for (int i = 1; i <= 2 * n + 1; ++i) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << calc(n + 1, n + 1);
}
