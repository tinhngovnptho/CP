/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-29
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

template <typename T> inline int isize(const T& a) { return a.size(); }

template <typename T1, typename T2> bool maximize(T1& a, T2 b) { return a < b ? a = b, true : false; }
template <typename T1, typename T2> bool minimize(T1& a, T2 b) { return a > b ? a = b, true : false; }


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
#endif // LOCAL

	int a, b;
	cin >> a >> b;
	cout << a + b;
}
