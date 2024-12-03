#include <bits/stdc++.h>

#define setIO(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

using namespace std;

template <typename T> inline int isize(const T& a) { return a.size(); }

template <typename T1, typename T2> bool maximize(T1& a, T2 b) { return a < b ? a = b, true : false; }
template <typename T1, typename T2> bool minimize(T1& a, T2 b) { return a > b ? a = b, true : false; }

const int maxN = 1e5 + 11;

int n, q;
int c[maxN];
vector<int> adj[maxN];
vector<pair<int, int> > queries;

namespace Sub123 {

	bool mark[maxN];

	void solve() {
		int cnt = 0;
		int min_c = 1e6 + 11;

		for (int i = 1; i <= n; ++i) minimize(min_c, c[i]);

		for (auto x : queries) {
			int u = x.first;
			int v = x.second;
			for (int i = u; i <= v; ++i) if (!mark[i] && c[i] != min_c) {
				cnt += c[i] - min_c, mark[i] = 1;
				c[i] = min_c;
			}
			cout << cnt << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); setIO("chand");

	cin >> n >> q;

	for (int i = 1; i <= n; ++i) cin >> c[i];

	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queries.resize(q);
	for (int i = 0; i < q; ++i) {
		cin >> queries[i].first >> queries[i].second;
	}

	Sub123::solve();
}

