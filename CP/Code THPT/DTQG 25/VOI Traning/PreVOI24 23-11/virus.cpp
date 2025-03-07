/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-23
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#if __cplusplus < 202002L
template <class T> int ssize(const T &a) { return a.size(); }
#endif // __cplusplus

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

using int64 = long long;
using Point = pair<int, int>;
using Data = pair<int, Point>;

const int INF = 1e9 + 11;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, s;
vector<Point> points;

bool isSide(int i, int j) {
	return (i > 0 && i <= m && j > 0 && j <= n);
}

namespace Sub12 {

	int dp[2011][2011];

	void solve() {
		priority_queue<Data, vector<Data>, greater<Data>> pq;

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = INF;
			}
		}

		for (Point x : points) {
			pq.emplace(0, x);
			dp[x.first][x.second] = 0;
		}

		while (!pq.empty()) {
			int t = pq.top().first;
			Point x = pq.top().second;
			pq.pop();

			for (int k = 0; k < 4; ++k) {
				int i = x.first + dx[k];
				int j = x.second + dy[k];
				if (isSide(i, j) && dp[i][j] == INF) {
					dp[i][j] = t + 1;
					Point p = {i, j};
					pq.emplace(dp[i][j], p);
				}
			}
		}

		int ans = 0;

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				maximize(ans, dp[i][j]);
			}
		}

		cout << ans;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("virus.inp", "r", stdin);
	freopen("virus.out", "w", stdout);

	cin >> m >> n >> s;
	points.resize(s);
	for (int i = 0; i < s; ++i) {
		cin >> points[i].first >> points[i].second;
	}

	return Sub12::solve(), 0;
}
