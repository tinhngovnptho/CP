/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-24
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int maxN = 4e6 + 11;
const int INF = 1e9 + 11;

int n, k, x, y;
vector<pair<int, int> > List, adj[maxN];
int d[maxN];

bool isSide(int x, int y) {
	return (x > 0 && x <= n && y > 0 && y <= n);
}

int Get(int x, int y) {
	return x * (n - 1) + y;
}

void BFS01(int s) {
	for (int i = 1; i <= n * n; ++i) d[i] = INF;
	deque<int> dq;
	dq.push_back(s);
	d[s] = 0;
	while (dq.size()) {
		int u = dq.front();
		dq.pop_front();
		for (auto x : adj[u]) {
			int v = x.first;
			int w = x.second;
			if (d[v] < INF) continue;
			d[v] = d[u] + w;
			if (w == 0) dq.push_front(v);
			else dq.push_back(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("jgame.inp", "r", stdin);
	freopen("jgame.out", "w", stdout);

	cin >> n >> k >> x >> y;
	for (int i = 1, u, v; i <= k; ++i) {
		cin >> u >> v;
		List.emplace_back(u, v);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int id = Get(i, j);
			for (int d = 0; d < 4; ++d) {
				int ii = i + dx[d];
				int jj = j + dy[d];
				if (isSide(ii, jj)) {
					adj[id].emplace_back(Get(ii, jj), 1);
				}
			}
			for (auto l : List) {
				if (l.first == i  || l.second == j) {
					adj[id].emplace_back(Get(l.first, l.second), 0);
				}
			}
		}
	}

	BFS01(Get(x, y));

	cout << min({d[Get(1, n)], d[Get(1, 1)], d[Get(n, 1)], d[Get(n, n)]});
}
