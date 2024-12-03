/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-28
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

void solve() {
	string s;
	cin >> s;

	s = "  " + s;
	int ans = 0;

	for (int i = 2; i < isize(s); ++i) if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
		s[i] = '?';
		ans++;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("g.inp", "r", stdin);
	freopen("g.out", "w", stdout);
#endif // LOCAL

	int t; cin >> t; while (t--) {
		solve();
	}
}
