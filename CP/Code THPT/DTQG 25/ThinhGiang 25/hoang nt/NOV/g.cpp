/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-24
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

const int maxN = 511;
const int MAX = maxN * maxN;

int n, q, a[maxN], b[maxN], dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("g.inp", "r", stdin);
	freopen("g.out", "w", stdout);
#endif // LOCAL

	cin >> n;
	int sumB = 0, sumall = 0;
	memset(dp, -0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		sumB += b[i];
		sumall += max(a[i], b[i]);
		for (int j = MAX - 1; j >= a[i]; --j) {
			dp[j] = max(dp[j] + b[i], dp[j - a[i]] + a[i]);
		}
		for (int j = 0; j < a[i]; ++j) dp[j] += b[i];
	}

	for (int j = MAX - 2; ~j; --j) maximize(dp[j], dp[j + 1]);

	int win = 0, lose = 0, draw = 0;

	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (dp[y + 1] > x + y) win++;
		else if (sumB >= x || sumall >= x + y) draw++;
		else lose++;
	}

	cout << win << ' ' << draw << ' ' << lose;
}
