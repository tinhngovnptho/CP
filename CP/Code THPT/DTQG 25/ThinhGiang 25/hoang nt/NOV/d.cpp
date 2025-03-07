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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("d.inp", "r", stdin);
	freopen("d.out", "w", stdout);
#endif // LOCAL

	int n; cin >> n;
	vector<int> t(n + 2), f(n + 2);

	for (int i = 1; i <= n; ++i) cin >> t[i];
	for (int i = 1; i <= n; ++i) cin >> f[i];

	int64 tmp = 0;
	priority_queue<int64> pq;
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		if (tmp <= t[i]) {
			tmp += f[i];
			pq.push(f[i]);
			ans++;
		} else if (ssize(pq) && pq.top() > f[i]) {
			tmp -= pq.top();
			pq.pop();
			tmp += f[i];
			pq.push(f[i]);
		}
	}

	cout << ans;
}
