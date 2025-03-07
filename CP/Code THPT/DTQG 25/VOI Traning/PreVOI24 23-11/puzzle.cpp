/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-24
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

const int mod = 1e9 + 7;

int a[11], b[11];

int n, m, k, l;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("puzzle.inp", "r", stdin);
	freopen("puzzle.out", "w", stdout);

	cin >> n >> m >> k >> l;
	for (int i = 1; i <= k; ++i) {
		cin >> a[i] >> b[i];
	}

	cout << 0;
}
