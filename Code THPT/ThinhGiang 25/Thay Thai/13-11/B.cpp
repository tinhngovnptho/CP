/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-13
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef tinhnop_local
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // tinhnop_local

#define ALL(v) (v).begin(), (v).end()

#if __cplusplus < 202002L
template <typename T> int ssize(const T &a) { return a.size(); }
#endif // __cplusplus

template <typename T1, typename T2>
bool maximize(T1 &a, T2 b) { return a < b ? a = b, true : false; }

template <typename T1, typename T2>
bool minimize(T1 &a, T2 b) { return a > b ? a = b, true : false; }

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
	static_assert(D >= 1, "Init Error");
	template <typename... Args>
	vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template <typename T>
struct vec<T, 1> : public vector<T> {
	vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};
//} end of template

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#define task "B"
	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	//____________________________________
	int n, m;
	cin >> n >> m;
	vec<char, 2> a(n + 2, m + 2);
	vec<int, 2> d(n + 2, m + 2, n + m + 10);
	vec<pair<char, int>, 2> dp(n + 2, m + 2);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	d[n][m] = 1;

	vector<pair<pair<char, int> , pair<int, int>> > v;

	for (int sum = n + m - 1; sum >= 2; --sum) {
		int x = (sum > m + 1 ? sum - m : 1);
		int y = sum - x;
		v.clear();
		for (;  x <= n && y > 0; x++, y--) {
			if (a[x][y] == '#') continue ;
			dp[x][y] = {a[x][y], min(d[x + 1][y], d[x][y + 1])};
			debug(x, y, dp[x][y]);
			pair<int , int> c = {x, y};

			if (dp[x][y].second != n + m + 10) v.push_back({dp[x][y], c});
		}
		sort(ALL(v));
		for (int i = 0; i < ssize(v); ++i) {
			d[v[i].second.first][v[i].second.second] = i + 1;
		}
	}

	int x = 1, y = 1;
	while (x <= n && y <= m) {
		cout << a[x][y];
		if (dp[x][y].second == d[x + 1][y]) x++;
		else y++;
	}
}
