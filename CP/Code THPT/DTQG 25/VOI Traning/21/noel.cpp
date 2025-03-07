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

void logtime() {
	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
//}

const int MAXN = 2009;

int n, d, a[MAXN];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0); atexit(logtime);
#ifdef tinhnop_local
	freopen("noel.inp", "r", stdin);
	freopen("noel.out", "w", stdout);
#endif // tinhnop_local
//________________________________________
	cin >> n >> d;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}

}
