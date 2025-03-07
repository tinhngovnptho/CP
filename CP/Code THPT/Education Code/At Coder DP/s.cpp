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
string k;
int d, dp[10011][101];

const int mod = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int calc(const string &a, int i, int sum, bool tight) {
	if (i < 0) {
		return sum == 0;
	}

	int &ret = dp[i][sum];
	if (!tight && ~ret) return ret;

	int max_digt = tight ? (a[i] - '0') : 9;
	int res = 0;
	for (int c = 0; c <= max_digt; ++c) {
		bool new_tight = tight && (c == max_digt);
		add(res, calc(a, i - 1, (sum + c) % d, new_tight));
	}

	if (!tight) ret = res;
	return res;
}

void tinhnop() {
	cin >> k >> d;
	reverse(k.begin(), k.end());
	memset(dp, -1, sizeof(dp));
	cout << (calc(k, k.size() - 1, 0, true) - 1 + mod) % mod;
}
////////////////////////////////////////
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("s.inp", "r", stdin);
	freopen("s.out", "w", stdout);
///////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
