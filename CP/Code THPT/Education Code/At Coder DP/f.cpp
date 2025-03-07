/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-15
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef tinhnop_local
	#include "D:\Tinhnopro\header\debug.h"
#else
	#define debug(...) 0
#endif // tinhnop_local

#define ALL(v) (v).begin(), (v).end()
#define ssize(s) ((signed) (s).size())


void tinhnop() {
	string a, b;
	cin >> a >> b;
	int n = ssize(a);
	a = " " + a;
	int m = ssize(b);
	b = " " + b;

	vector<vector<int> > dp;
	dp.assign(n + 2, vector<int>(m + 2, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	deque<char> st;
	int i = n, j = m;
	while (i && j) {
		if (a[i] == b[j]) {
			st.push_back(a[i]);
			i--;
			j--;
		} else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		} else j--;
	}

	while (ssize(st)) {
		cout << st.back();
		st.pop_back();
	}
}
///////////////////////////////////////////
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("f.inp", "r", stdin);
	freopen("f.out", "w", stdout);
///////////////////////////////////////////
	tinhnop();
	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
