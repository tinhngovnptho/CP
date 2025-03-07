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

const int maxN = 1e5 + 11;
const int INF = 1e9 + 11;

int n, m, q;
int w[maxN];
vector<int> adj[maxN];
pair<int, int> queries[maxN];

namespace Sub1 {

	bool check() {
		return (n <= 10 && m <= 20 && q <= 10);
	}

	int a, b;
	bool vist[maxN];
	vector<vector<int>> paths;

	void Gen(vector<int> path, int u) {
		if (u == b) {
			paths.push_back(path);
			return ;
		}
		for (int v : adj[u]) if (!vist[v]) {
			path.push_back(v);
			vist[v] = true;
			Gen(path, v);
			vist[v] = false;
			path.pop_back();
		}
	}

	void solve() {
		for (int i = 1; i <= q; ++i) {
			a = queries[i].first;
			b = queries[i].second;
			vist[a] = true;
			paths.clear();
			Gen({a}, a);
			if (paths.size() < 2) {
				cout << -1 << '\n';
				continue;
			}
			vector<int> ans;
			for (vector<int> &x : paths) {
				int mx = -1;
				for (int v : x) {
					maximize(mx, w[v]);
				}
				ans.push_back(mx);
			}
			sort(ans.begin(), ans.end());
//			debug(ans);
			cout << ans[1] << '\n';
		}
	}
}

namespace SubTinh {

	void solve() {
		for (int i = 1; i <= q; ++i) {
			cout << -1 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("robot.inp", "r", stdin);
	freopen("robot.out", "w", stdout);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= q; ++i) {
		cin >> queries[i].first >> queries[i].second;
	}

	if (Sub1::check()) return Sub1::solve(), 0;
	SubTinh::solve();
}
