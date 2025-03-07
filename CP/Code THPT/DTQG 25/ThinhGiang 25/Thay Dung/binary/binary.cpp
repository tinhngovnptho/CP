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

int k, a[1 << 11];
vector<int> levels[11];

void solve(int l, int r, int lev) {
	if (l > r) return ;
	int mid = (l + r) >> 1;
	levels[lev].push_back(a[mid]);
	solve(l, mid - 1, lev + 1);
	solve(mid + 1, r, lev + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("binary.inp", "r", stdin);
	freopen("binary.out", "w", stdout);

	cin >> k;
	for (int i = 1; i < (1 << k); ++i) {
		cin >> a[i];
	}

	solve(1, (1 << k) - 1, 1);

	for (int lev = 1; lev <= k; ++lev) {
		for (int node : levels[lev]) cout << node << ' ';
		cout << '\n';
	}
}
