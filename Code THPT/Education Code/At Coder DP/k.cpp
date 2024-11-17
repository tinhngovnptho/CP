/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-16
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

int n, k, a[111];

void tinhnop() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<bool> dp(k + 2, false);

	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) if (j >= a[i] && !dp[j - a[i]]) dp[j] = true;
	}

	cout << (dp[k] ? "First" : "Second");
}
////////////////////////////////////////
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("k.inp", "r", stdin);
	freopen("k.out", "w", stdout);
///////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
