/*
	Author: tinhnopro
	created: 26.02.2025 00:53:29
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "newcar"

using namespace std;

using i64 = long long;

struct Point {
	int x, y; 

	Point(int _x = 0, int _y = 0): x(_x), y(_y) {}
};

int k, m, n, R, z[201];
Point a[50], b[201];

int sqr(int x) {
	return x * x; 
}

float dist(const Point& a, const Point& b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> k >> m >> n >> R; 

	for (int i = 0; i < m; ++i) {
		cin >> a[i].x >> a[i].y; 
	}	

	for (int i = 1; i <= n; ++i) {
		cin >> b[i].x >> b[i].y >> z[i];
	}

	int ans = 0;

	for (int mask = 0; mask < (1 << m); ++mask) {
		if (__builtin_popcount(mask) == k) {
			int cnt = 0; 
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < m; ++j) if ((mask >> j) & 1) {
					if (dist(b[i], a[j]) <= R) {
						cnt += z[i];
						break;
					}
				}
			}

			ans = max(ans, cnt);
		}
	}

	cout << ans; 
}