#include <bits/stdc++.h>

#define setIO(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

using namespace std;

template <typename T> inline int isize(const T& a) { return a.size(); }

template <typename T1, typename T2> bool maximize(T1& a, T2 b) { return a < b ? a = b, true : false; }
template <typename T1, typename T2> bool minimize(T1& a, T2 b) { return a > b ? a = b, true : false; }

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
	static_assert(D >= 1, "Init Error");
	template <typename... Args>
	vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};

template <typename T>
struct vec<T, 1> : public vector<T> {
	vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};

int m, n, q;
vec<int, 2> a;
vector<pair<int, int> > queries;

namespace Sub12 {

	bool check() {
		return n <= 400 && m <= 400;
	}

	void solve() {
		vec<int64_t, 2> dp(m + 2, n + 2);

		for (int idx = 1; idx <= q; ++idx) {
			int x = queries[idx].first;
			int y = queries[idx].second;
			dp = vec<int64_t, 2>(m + 2, n + 2, 0);
			dp[x][y] = -1;
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= n; ++j) if (dp[i][j] != -1) {
					if (dp[i - 1][j] != -1) maximize(dp[i][j], dp[i - 1][j] + a[i][j]);
					if (dp[i][j - 1] != -1) maximize(dp[i][j], dp[i][j - 1] + a[i][j]);
				}
			}
			cout << dp[m][n] << '\n';
		}
	}
}

namespace Sub3 {

	void solve() {
		vec<int64_t, 2> dp(m + 2, n + 2, 0), mark(m + 2, n + 2, 0);

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			}
		}

		int i = m, j = n;
		vector<pair<int, int> > path;
		while (i != 1 || j != 1) {
			mark[i][j] = 1;
			path.emplace_back(i, j);
			if (i == 1) {
				j--;
				continue;
			}
			if (j == 1) {
				i--;
				continue;
			}
			if (dp[i - 1][j] > dp[i][j - 1]) i--;
			else j--;
		}

		path.push_back({1, 1});

		reverse(path.begin(), path.end());

		for (int idx = 1; idx <= q; ++idx) {
			int x = queries[idx].first;
			int y = queries[idx].second;
			if (!mark[x][y]) {
				cout << dp[m][n] << '\n';
				continue;
			}

			int pos = lower_bound(path.begin(), path.end(), make_pair(x, y)) - path.begin() + 1;
			if (pos < isize(path)) {
				pair<int, int> d = path[pos];
				pair<int, int> d2 = path[pos - 1];
				if (dp[d.first][d.second - 1] == dp[d.first - 1][d.second]) {
					cout << dp[m][n] << '\n';
				} else cout << dp[m][n] - dp[d2.first][d2.second] + min(dp[d.first][d.second - 1], dp[d.first - 1][d.second]) << '\n';
			} else {
				cout << dp[m][n] << '\n';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); setIO("robot");

	cin >> m >> n >> q;
	a = vec<int, 2>(m + 2, n + 2);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	queries.resize(q + 2);

	for (int i = 1; i <= q; ++i) {
		cin >> queries[i].first >> queries[i].second;
	}

	if (Sub12::check()) return Sub12::solve(), 0;
	Sub3::solve();
}
