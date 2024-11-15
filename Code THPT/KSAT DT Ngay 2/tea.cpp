/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-14
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#define ALL(v) (v).begin(), (v).end()
#define ssize(s) (int) (s).size()

#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template <typename A, typename B> bool minimize(A &a, B b)  { return a > b ? a = b, true : false; }
template <typename A, typename B> bool maximize(A &a, B b)  { return a < b ? a = b, true : false; }
//} end of template

const int MAXN = 1e6 + 11;

pair<int, int> t[MAXN];

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	file("tea");
//__________________________________
	int n, m;
	cin >> n >> m;
	vector<char> res(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> t[i].first;
		t[i].second = i;
	}

	sort(t + 1, t + n + 1);

	for (int i = 0; i < m; ++i) {
		int l, r; cin >> l >> r;
	}

	cout << m << '\n';
	for (int i = 1; i <= n; ++i) {
		char x = (i % 2 == 0 ? 'C' : 'S');
		res[t[i].second] = x;
	}

	for (int i = 1; i <= n; ++i) cout << res[i];
}
