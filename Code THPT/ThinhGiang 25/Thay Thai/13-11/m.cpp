/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-14
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef tinhnop_local
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // tinhnop_local

#define ALL(v)	(v).begin(), (v).end()
#define ssize(s) ((int) (s).size())

template <typename A, typename B>
bool minimize(A &a, B b) {
	return a > b ? a = b, true : false;
}

template <typename A, typename B>
bool maximize(A &a, B b) {
	return a < b ? a = b, true : false;
}

void tinhnop();

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
#ifdef tinhnop_local
	freopen("m.inp", "r", stdin);
	freopen("m.out", "w", stdout);
#endif // tinhnop_local
	tinhnop();
//	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
//}

const int mod = 1e9 + 7;

void tinhnop() {
	string s;
	cin >> s;
	int n = ssize(s);
	s = " " + s;
	vector<int> dp(n + 2, 0);

	auto add = [&] (int &a, int b) -> void {
		a += b;
		if (a >= mod) a -= mod;
	};

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		add(dp[i], dp[i - 1]);
		if (s[i] != s[i - 1]) add(dp[i], dp[i - 2]);
	}

	cout << dp[n];
}
