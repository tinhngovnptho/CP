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

#define TASK "cutcake2"

using namespace std;

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	friend istream& operator >>(istream& in, Point& p) {
		in >> p.x >> p.y;
		return in;
	}
};

struct Cake {
	Point v[3];
	Cake() {}

	friend istream& operator >>(istream& in, Cake& c) {
		in >> c.v[0] >> c.v[1] >> c.v[2];
		return in;
	}

	int getmax_x() {
		return max({v[0].x, v[1].x, v[2].x});
	}

	int getmin_x() {
		return min({v[0].x, v[1].x, v[2].x});
	}

	int getmax_y() {
		return max({v[0].y, v[1].y, v[2].y});
	}

	int getmin_y() {
		return min({v[0].y, v[1].y, v[2].y});
	}
};

const int maxN = 1e5 + 5;
const int maxV = 1e6 + 5;

int n, q;
Cake a[maxN];
int prefix_x[maxV], prefix_y[maxV];

pair<bool, int> get_query(string& op) {
	bool isX = false;
	if (op[0] == 'x') isX = true;
	op.erase(0, 4);
	int ret = 0;

	for (size_t i = 0; i < op.size(); ++i) {
		ret = ret * 10 + (op[i] - '0');
	}
	return {isX, ret};
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(false);
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		prefix_x[a[i].getmin_x() + 1]++;
		prefix_x[a[i].getmax_x()]--;
		prefix_y[a[i].getmin_y() + 1]++;
		prefix_y[a[i].getmax_y()]--;
	}

	for (int i = 1; i < maxV; ++i) {
		prefix_x[i] += prefix_x[i - 1];
		prefix_y[i] += prefix_y[i - 1];
	}

	cin >> q;

	string op;

	cin.ignore();

	while (q--) {
		getline(cin, op);
		pair<bool, int> query = get_query(op);
//		debug(query);
		if (query.first) {
			cout << prefix_x[query.second] << '\n';
		} else {
			cout << prefix_y[query.second] << '\n';
		}
	}
}

