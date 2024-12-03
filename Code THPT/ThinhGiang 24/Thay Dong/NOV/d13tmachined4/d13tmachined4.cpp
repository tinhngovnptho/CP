/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-25
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

using int64 = long long;

const int maxN = 1e5 + 11;

int n, q;
int Time[maxN];

int s, t, c;
int cur;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("d13tmachined4.inp", "r", stdin);
	freopen("d13tmachined4.out", "w", stdout);
#endif // LOCAL

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
			char x; cin >> x;
			Time[i] = x - '0';
	}

	while (q--) {
		cin >> s >> t >> c;
		if (s > t) swap(s, t);
		deque<pair<int, int>> dq;
		for (int i = s; i <= t; ++i) {
			// dp[i] = min(dp[j]) + a[i] (i - C <= j <= i)
			while (!dq.empty() && dq.front().second < i - c) dq.pop_front();

			if (dq.empty()) cur = Time[i];
			else cur = dq.front().first + Time[i];

			while (!dq.empty() && dq.back().first >= cur) dq.pop_back();
			dq.push_back({cur, i});
		}
		cout << dq.back().first << '\n';
	}
}
