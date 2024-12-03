/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-21
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

const int maxN = 5e4 + 11;

int n, k;
vector<int> adj[maxN];
char s[maxN];
int sz[maxN], isDel[maxN];

int getSize(int u, int parent = -1) {
	sz[u] = 1;
	for (int v : adj[u]) if (v != parent && !isDel[v]) {
		sz[u] += getSize(v, u);
	}
	return sz[u];
}

int findCentroid(const int &len, int u, int parent = -1) {
	for (int v : adj[u]) if (v != parent && !isDel[v] && sz[v] > len) {
		return findCentroid(len, v, u);
	}
	return u;
}

void CentroidDecomp(int u, int parent = -1) {
	int len = getSize(u) >> 1;
	int centroid = findCentroid(len, u);


	isDel[centroid] = true;

	for (int v : adj[centroid]) if (!isDel[v]) {
		CentroidDecomp(v, centroid);
	}
}

bool check(int len) {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("noel.inp", "r", stdin);
	freopen("noel.out", "w", stdout);
#endif // ONLINE_JUDGE

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;

	int lo = 2, hi = n - n % 2;

	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) lo = mid;
		else hi = mid - 2;
	}

	maximize(ans, lo);

	int lo = 1, hi = n - (n % 2 == 0);
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) lo = mid;
		else hi = mid - 2;
	}

	maximize(ans, lo);

	cout << ans;
}
