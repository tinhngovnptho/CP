/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 11, INF = 1e9 + 11; 

int n, k;
int64_t a[MAXN], b[MAXN];

namespace Sub1 {
	struct Node {
		int64_t val;
		int64_t mx1, mx2;
		Node(int64_t _val, int64_t _mx, int64_t _mx2) : val(_val), mx1(_mx), mx2(_mx2) {} 
		Node() {
			val = mx1 = mx2 = 0;
		}
	} dp[MAXN];

	void solve(void) {
		a[n + 1] = -INF;
		b[n + 1] = -INF;
		for (int i = 1; i <= n + 1;  ++i) {
			dp[i] = {a[i] * b[i], a[i], b[i]};
			for (int j = max(1, i - k); j < i; ++j) {
				Node res = {0, 0, 0}; 
				res.mx1 = max(dp[i].mx1, dp[j].mx1);
				res.mx2 = max(dp[i].mx2, dp[j].mx2);
				res.val = 1ll * res.mx1 * res.mx2;
				if (dp[i].val > res.val) dp[i] = res; 
			}
			// cout << dp[i].val << '\n';
		}
		cout << dp[n + 1].val;
	}
}

void run_case(void) {
	cin >> n >> k; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}

	if (n <= 3000) return void(Sub1::solve());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

#define task "mnjump"
	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop\n";
}
