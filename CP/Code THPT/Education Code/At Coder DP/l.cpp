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

const int maxN = 3011;

int n, a[maxN];
int64 dp[maxN][maxN][2];

int64 calc(int l, int r, bool turn) {
	if (l > r) {
		return 0LL;
	}
	int64 &ret = dp[l][r][turn];
	if (~ret) return ret;
	ret = 0LL;
	if (!turn) {
		ret = max(a[r] + calc(l, r - 1, turn ^ 1), a[l] + calc(l + 1, r, turn ^ 1));
	} else {
		ret = min(calc(l, r - 1, turn ^ 1) - a[r], calc(l + 1, r, turn ^ 1) - a[l]);
	}
	return ret;
}

void tinhnop() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cout << calc(1, n, 0);
}
////////////////////////////////////////
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("l.inp", "r", stdin);
	freopen("l.out", "w", stdout);
////////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
