#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef tinhnop_local
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // tinhnop_local

#define	file(name)  if (fopen(name".inp", "r")) \
freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)


// Author: tinhnopro (Tinh nop)

void tinhnop(void);

int32_t main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("DELDIGIT2");
#ifdef tinhnop_local
	freopen("D:\\Tinhnopro\\docs\\log.txt", "w", stderr);
#endif // tinhnop_local

	int testcases = 1;
//	cin >> testcases;
	for (int test = 1; test <= testcases; ++test) {
//		cout << "Case #" << test << ": ";
		tinhnop();
	}

	return 0;
}
//}

const int MAXN = 111;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 11;

int n;
int64_t a[MAXN];
vector<int64_t> v[MAXN];
int sum[MAXN][MAX];
int dp[MAXN][MAX];

string int_to_str(int64_t x) {
	string res = "";
	while (x) {
		res = char('0' + x % 10) + res;
		x /= 10;
	}
	return res;
}

int64_t str_to_int(string s) {
	int64_t res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res = 1LL * res * 10 + (s[i] - '0');
	}
	return res;
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void tinhnop() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		string tmp = int_to_str(a[i]);
		string d;
		int m = tmp.size();
		for (int mask = 1; mask < (1 << m); ++mask) {
			d = "";
			for (int c = 0; c < m; ++c) if ((mask >> c) & 1) {
				d.push_back(tmp[c]);
			}
			v[i].push_back(str_to_int(d));
		}
	}

	for (int i = 1; i <= n; ++i) {
		sort(v[i].begin(), v[i].end());
		v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
		debug(v[i]);
	}

	for (int j = 0; j < v[1].size(); ++j) {
		dp[1][j] = 1;
		if (j) {
			sum[1][j] = sum[1][j - 1];
			add(sum[1][j], dp[1][j]);
		} else sum[1][j] = dp[1][j];
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			int cur = upper_bound(v[i - 1].begin(), v[i - 1].end(), v[i][j]) - v[i - 1].begin() - 1;
			if (cur < 0) continue;
			add(dp[i][j], sum[i - 1][cur]);
			if (j) {
				sum[i][j] = sum[i][j - 1];
				add(sum[i][j], dp[i][j]);
			} else sum[i][j] = dp[i][j];
		}
	}
	int res = 0;

	for (int j = 0; j < v[n].size(); ++j) add(res, dp[n][j]);

	cout << res;
}
