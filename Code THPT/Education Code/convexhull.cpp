/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-18
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#define ssz(s) ((int) (s).size())
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;
typedef unsigned long long uint64;
////////////////////////////////////////

const int maxN = 1e6 + 11;

int a[maxN], n;
int64 dp[maxN], C;

struct Line {
	int64 k, m;
	bool operator <(const Line &other) const {
		return k < other.k;
	}
	int64 eval(int64 x) {
		return k * x + m;
	}
};

struct Frac {
	int64 a, b;
	bool operator >=(const Frac &other) const {
		return a * other.b >= other.a * b;
	}

	bool operator <(const Frac &other) const {
		return a * other.b < other.a * b;
	}

	Frac(int64 _a, int64 _b) : a(_a), b(_b) {}
};

Frac intersection(Line line1, Line line2) {
	// ax + b = cx + d -> (a - c)x = d - b
	if (line1.k < line2.k) swap(line1, line2);
	Frac ret(line1.m - line2.m, line1.k - line2.k);
}

deque<Line> hull;

void add(Line L) {
	while (ssz(hull) > 1 && intersection(hull.back(), hull[ssz(hull) - 2]) >= intersection(hull.back(), L))
		hull.pop_back();

	hull.push_back(L);
}

int64 GetF(int64 x) {
	Frac X = {x, 1};
	while (ssz(hull) > 1 && intersection(hull[0], hull[1]) >= X) hull.pop_front();

	return hull.front().eval(x);
}

void ins(int i) {
	Line L;
	L.k = -2 * a[i];
	L.m = 1LL * a[i] * a[i] + dp[i];
	add(L);
}

void tinhnop() {
	cin >> n >> C;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dp[1] = 0;
	ins(1);
	for (int i = 2; i <= n; ++i) {
		dp[i] = C + 1LL * a[i] * a[i] + GetF(a[i]);
		cout << dp[i] << " " << GetF(a[i]) << '\n';
		ins(i);
	}
	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}

