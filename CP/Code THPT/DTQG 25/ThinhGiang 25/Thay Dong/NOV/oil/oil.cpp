/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-25
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

const int maxN = 1e6 + 11;

int n, s;
int64_t a[maxN];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("oil.inp", "r", stdin);
	freopen("oil.out", "w", stdout);
#endif // LOCAL

	cin >> n >> s;

	int64_t ans = 0;
	priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] -= s * i;
		pq.push(a[i]);
		pq.push(a[i]);
		ans += a[i] - pq.top();
		pq.pop();
	}

	cout << ans;
}
