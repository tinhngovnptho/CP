/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
//{ template
#include <bits/stdc++.h>


#ifdef tinhnop_local
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // tinhnop_local

#define file(name)	if (fopen(name".inp", "r")) \
					freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

using namespace std;

void tinhnop(void);

int main(void) {
	cin.tie(0)->sync_with_stdio(0);

	file("diffjump");

	tinhnop();

#ifdef tinhnop_local
	cerr << "\nExecution time: " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
#endif // tinhnop_local
}
//}

const int MAX = 5e5 + 11;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 11;

int m, n, k;
int a[711][711], dp[711][711];
int64_t pref[711][711];
vector<pair<int, int> > pos[MAX];

vector<int> compressor;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += MOD;
}


void tinhnop() {
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			compressor.push_back(a[i][j]);
		}
	}

	sort(compressor.begin(), compressor.end());
	compressor.resize(unique(compressor.begin(), compressor.end()) - compressor.begin());

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = lower_bound(compressor.begin(), compressor.end(), a[i][j]) - compressor.begin() + 1;
			pos[a[i][j]].emplace_back(i, j);
		}
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == 1 && j == 1) {
				dp[i][j] = 1;
				pref[i][j] = 1;
				continue;
			}
			add(dp[i][j], pref[i - 1][j - 1]);
			int x = a[i][j];
			for (auto d : pos[x]) {
				if (d.first == i) break;
				if (d.second < j) sub(dp[i][j], dp[d.first][d.second]);
			}
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + dp[i][j];
			pref[i][j] %= MOD;
		}
	}

	cout << dp[m][n] << '\n';
}
