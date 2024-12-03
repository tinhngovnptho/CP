/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-22
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

const int maxN = 5e5 + 11;

int n;
pair<int, int> a[maxN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("c.inp", "r", stdin);
	freopen("c.out", "w", stdout);
#endif // LOCAL

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);

	int sz_S1 = a[n].first;

	for (int sz_S2 = a[sz_S1].first; sz_S2 + sz_S1 <= n; ++sz_S2) {
		int sz_S3 = n - sz_S1 - sz_S2;
		if (a[sz_S1 + sz_S2].first <= sz_S3) {
			cout << sz_S1 << ' ';
			for (int i = 1; i <= sz_S1; ++i) cout << a[i].second << ' ';
			cout << '\n' << sz_S2 << ' ';
			for (int i = sz_S1 + 1; i <= sz_S1 + sz_S2; ++i) cout << a[i].second << ' ';
			exit(0);
		}
	}
	cout << -1;
}
