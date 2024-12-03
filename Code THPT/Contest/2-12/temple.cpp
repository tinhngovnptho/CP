/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-03
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define TASK ""

using namespace std;

template <typename T>
int isize(const T& a) { return a.size(); }

template <typename T1, typename T2>
bool maximize(T1& a, T2 b) { return a < b ? a = b, 1 : 0; }

template <typename T1, typename T2>
bool minimize(T1& a, T2 b) { return a > b ? a = b, 1 : 0; }

const int maxN = 1e5 + 11;

using ii = pair<int, int>;

struct Point {
	int x, y;

	Point() {x = y = 0; }
	Point(int _x, int _y) : x(_x), y(_y) {}
};

Point points[maxN];

int sqr(int x) {
	return x * x;
}

double dist(const Point& a, const Point& b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int mark[5005][5005];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (ifstream(TASK ".inp")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> points[i].x >> points[i].y;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {

		}
	}
}
