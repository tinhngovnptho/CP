/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-26
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("mindiff.inp", "r", stdin);
	freopen("mindiff.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<int> a(n + 2), diff(n + 2);

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	sort(a.begin() + 1, a.begin() + n + 1);

	for (int i = 2; i <= n; ++i) {
		diff[i] = a[i] - a[i - 1];
	}

	k = n - k;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 2; i <= k; ++i) {
		pq.push(diff[i]);
	}

	int res = pq.top() + a[k] - a[1];

	for (int i = 2; i <= n - k + 1; ++i) {
		int j = i + k - 1;
		if (pq.size() && diff[i] == pq.top()) pq.pop();
		pq.push(diff[j]);
		minimize(res, pq.top() + a[j] - a[i]);
	}

	cout << res;
}
