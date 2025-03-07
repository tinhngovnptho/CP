/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-23
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#if __cplusplus < 202002L
template <class T> int ssize(const T &a) { return a.size(); }
#endif // __cplusplus

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

using int64 = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);


}
