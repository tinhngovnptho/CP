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
	freopen("circle.inp", "r", stdin);
	freopen("circle.out", "w", stdout);

	int k, n;
	cin >> k >> n;
	int sum = 0;
	bool check = false;
	for (int i = 0; i < n; ++i) {
		int t; char c;
		cin >> t >> c;
		sum += t;
		if (sum >= 210 && !check) {
			cout << k;
			check = true;
		}
		if (c == 'T') {
			k++;
			if (k > 8) k -= 8;
		}
	}
}
