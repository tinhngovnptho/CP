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

const int maxN = 1e6 + 11;

int n;
vector<int> adj[maxN];

int depth[maxN], dp[maxN], par[maxN], pos[maxN], ans[maxN];

void dfs(int u, int parent = -1) {
	dp[u] = 1;
	for (int v : adj[u]) if (v ^ parent) {
		depth[v] = depth[u] + 1;
		par[v] = u;
		dfs(v, u);
		maximize(dp[u], dp[v] + 1);
	}
}

bool cmp(const int &a, const int &b) {
	return dp[a] > dp[b];
}

vector<int> List;

void calc(int u) {
	static int timeDFS = 0;
	pos[u] = ++timeDFS;
	for (int v : adj[u]) if (v ^ par[u]) {
		calc(v);
		if (pos[v] != pos[u] + 1) {
			List.push_back(dp[v]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("a.inp", "r", stdin);
	freopen("a.out", "w", stdout);
#endif // ONLINE_JUDGE

	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		u++; v++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	for (int i = 1; i <= n; ++i) {
		sort(begin(adj[i]), end(adj[i]), cmp);
	}

	calc(1);
	List.push_back(dp[1]);
	sort(begin(List), end(List), greater<int>());

	int cur = 1, cnt = 0;

	for (int x : List) {
		ans[cur] = ++cnt;
		cur += x;
	}

	for (int i = 2; i <= n; ++i) {
		if (ans[i] == 0) ans[i] = ans[i - 1];
	}

	for (int i = 2; i <= n; ++i) cout << ans[i] << ' ';
}
