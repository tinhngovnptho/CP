/**
 * author: tinhnopro (tinh nop)
 * created: $TODAY_UTC
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define setIO(name) \
if (ifstream(name".inp")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

using namespace std;

template <typename T> int isize(const T& a) { return a.size(); }

template <typename T1, typename T2> bool maximize(T1& a, T2 b) { return a < b ? a = b, true : false; }
template <typename T1, typename T2> bool minimize(T1& a, T2 b) { return a > b ? a = b, true : false; }


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0); setIO("");

}
