/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-06
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

const int maxN = 205;
const int maxW = 20005;

int n, a[maxN];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen("persimmon.inp", "r")) {
		freopen("persimmon.inp", "r", stdin);
		freopen("persimmon.out", "w", stdout);
	}

	cin >> n;
	int sum = 0, res = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i <= n / 2 + (n & 1)) sum += a[i];
		res += a[i];
	}

	cout << sum << ' ' << res - sum;
}

