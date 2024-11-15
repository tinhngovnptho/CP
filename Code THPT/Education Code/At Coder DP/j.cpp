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
	freopen(".inp", "r", stdin);
	freopen(".out", "w", stdout);
#endif // tinhnop_local
	tinhnop();
//	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
//}

void tinhnop() {

}
