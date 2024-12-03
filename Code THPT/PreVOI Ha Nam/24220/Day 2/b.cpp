/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-02
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define TASK ""

using namespace std;

template <typename T> int isize(const T& a) { return a.size(); }

bool maximize(int& a, int b) {
	return a < b ? a = b, true : false;
}

bool minimize(int& a, int b) {
	return a > b ? a = b, true : false;
}

void solve() {
	int n; cin >> n;
	vector<int> c(n);
	for (auto &x : c) cin >> x;

	vector<int> cnt(n + 1);

	for (auto &x : c) cnt[x]++;

	int cnt1 = 0;

	for (auto &x : c) if (cnt[x] == 1) cnt1++;

	int ans = cnt1 / 2 + (cnt1 & 1);
	ans *= 2;

	for (int i = 1; i <= n; ++i) {
		if (cnt[i] > 1) ans++;
	}

	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (ifstream(TASK ".inp")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}

	int t; cin >> t; while (t--) {
		solve();
	}
}

