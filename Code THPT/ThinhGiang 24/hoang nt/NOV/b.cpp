/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-22
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

const int maxN = 1e5 + 11;

struct Node {
	int v, w;
	Node(int _v, int _w) : v(_v), w(_w) {}
	Node() : v(0), w(0) {}
};

struct Data {
	int cntE;
	int64 minC;
	Data() : cntE(0), minC(0) {}
	Data(int _cntE, int64 _minC) : cntE(_cntE), minC(_minC) {}
};

int n, k;
vector<Node> adj[maxN];
Data dp[maxN][111];

void dfs(int u, int parent = -1) {
	for (int i = 0; i <= k; ++i) dp[u][i] = {0, 0};

	for (Node x : adj[u]) {
		int v = x.v;
		int w = x.w;
		if (v == parent) continue;
		dfs(v, u);

		for (int i = k; ~i; --i) {
			Data mx = dp[u][i];
			if (dp[v][k].cntE + dp[u][i].cntE > mx.cntE) {
				mx.cntE = dp[v][k].cntE + dp[u][i].cntE;
				mx.minC = dp[v][k].minC + dp[u][i].minC;
			} else if (dp[v][k].cntE + dp[u][i].cntE == mx.cntE) {
				minimize(mx.minC, dp[v][k].minC + dp[u][i].minC);
			}
			if (i > 0) {
				if (dp[v][k - 1].cntE + dp[u][i - 1].cntE + 1 > mx.cntE) {
					mx.cntE = dp[v][k - 1].cntE + dp[u][i - 1].cntE + 1;
					mx.minC = dp[v][k - 1].minC + dp[u][i - 1].minC + w;
				} else if (dp[v][k - 1].cntE + dp[u][i - 1].cntE + 1 == mx.cntE) {
					minimize(mx.minC, dp[v][k - 1].minC + dp[u][i - 1].minC + w);
				}
			}
			dp[u][i] = mx;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("b.inp", "r", stdin);
	freopen("b.out", "w", stdout);
#endif //LOCAL

	cin >> n >> k;
	for (int i = 2, p, w; i <= n; ++i) {
		cin >> p >> w;
		adj[p].emplace_back(i, w);
	}

	dfs(1);

	Data ans = {0, 0};

	for (int i = 0; i <= k; ++i) {
		if (ans.cntE < dp[1][i].cntE) {
			ans = dp[1][i];
		} else if (ans.cntE == dp[1][i].cntE) {
			minimize(ans.minC, dp[1][i].minC);
		}
	}

	cout << ans.cntE << ' ' << ans.minC << '\n';
}
