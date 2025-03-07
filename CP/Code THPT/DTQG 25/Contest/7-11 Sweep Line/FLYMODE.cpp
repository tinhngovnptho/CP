  /*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif

using namespace std;

const int MAXN = 1e5 + 11;

int n, a[MAXN];

void run_case(void) {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	map<int, int> mp;
	for (int i = 1; i < n; ++i) {
		int mx = max(a[i], a[i + 1]);
		int mi = min(a[i], a[i + 1]);
		mp[mx]--;
		mp[mi]++;
	}

	int64_t ans = 0, sum = 0;
	for (auto x : mp) {
		sum += x.second;
		ans = max(ans, sum);
	}
	cout << ans;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("FLYMODE.inp", "r", stdin);
	freopen("FLYMODE.out", "w", stdout);

	int tests = 1;
//	cin >> tests;
	while (tests--) run_case();
//	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}

