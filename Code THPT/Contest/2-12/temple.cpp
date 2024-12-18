/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-05
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define TASK "temple"

using namespace std;

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	friend istream& operator >>(istream &in, Point &p) {
		in >> p.x >> p.y;
		return in;
	}

	bool inRange() {
		if (x < 0 || x > 5000) return false;
		if (y < 0 || y > 5000) return false;
		return true;
	}
};

const int maxN = 3005, maxV = 5005;

int n;
Point points[maxN];
bool mark[maxV][maxV];

inline int sqr(const int& x) {
	return x * x;
}

bool isPoint(const Point& p) {
	return mark[p.x][p.y];
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(false);
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> points[i];
		mark[points[i].x][points[i].y] = true;
	}

	int maxArea = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int dx = abs(points[i].x - points[j].x);
			int dy = abs(points[i].y - points[j].y);
			int Area = sqr(dx) + sqr(dy);

			Point c(points[i].x + dy, points[i].y + dx);
			Point d(points[j].x + dy, points[j].y + dx);

			if (c.inRange() && d.inRange() && isPoint(c) && isPoint(d))
				maxArea = max(maxArea, Area);
		}
	}

	cout << maxArea;
}
