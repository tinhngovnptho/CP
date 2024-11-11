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

using namespace std;

void Tinh_Nop(void);

int32_t main(void) {
	cin.tie(0), cout.tie(0)->sync_with_stdio(0);

	if (fopen("atcoder_dp_u.inp", "r")) {
		freopen("atcoder_dp_u.inp", "r", stdin);
		freopen("atcoder_dp_u.out", "w", stdout);
	}

	Tinh_Nop();

#ifdef tinhnop_local
	cerr << "\nExecution time : " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
#endif // tinhnop_local
}
//}

const int MAXN = 20;

int n;
int a[MAXN][MAXN];

void Tinh_Nop() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}


}
