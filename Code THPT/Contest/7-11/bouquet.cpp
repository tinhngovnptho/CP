/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 11;

int n;
pair<int, int> a[MAXN];

void maximize(int &a, int b) {
	if (a < b) a = b;
}

namespace Sub2 {

	int dp[MAXN];
	int bit[2 * MAXN];
	vector <int> pos[2 * MAXN];

	void update(int u, int val) {
		for (; u <= 2 * n; u += u & -u) maximize(bit[u], val);
	}

	int Get(int u) {
		int res = 0;
		for (; u > 0; u -= u & -u) maximize(res, bit[u]);
		return res;
	}

	void solve(void) {
		int res = 0;

		for (int i = 1; i <= n; ++i) {
			dp[i] = 1;
			for (int x : pos[i]) update(x, dp[x]);
			maximize(dp[i], Get(i - a[i].first - 1) + 1);
			maximize(res, dp[i]);

			pos[i + a[i].second + 1].push_back(i);
		}
		cout << res;
	}
}

void run_case(void) {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;

	return void(Sub2::solve());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("bouquet.inp", "r", stdin);
	freopen("bouquet.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
