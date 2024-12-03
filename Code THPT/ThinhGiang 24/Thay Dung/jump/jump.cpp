/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-27
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

const int maxN = 1511;
const int MAX = 1e6 + 5;
const int inf = 1e9 + 11;

int n, r, c;
int a[maxN][maxN];
vector<ii> pos[MAX];
int dp[maxN][maxN];

struct FendwickTree {
	int bit1[maxN], bit2[maxN];

	FendwickTree() {
		memset(bit1, -0x3f, sizeof(bit1));
		memset(bit2, -0x3f, sizeof(bit2));
	}

	void update_pref(int u, int val) {
		for (; u <= n; u += u & -u) maximize(bit1[u], val);
	}

	void update_suff(int u, int val) {
		for (; u > 0; u -= u & -u) maximize(bit2[u], val);
	}

	int get_pref(int u) {
		int res = -inf;
		for (; u > 0; u -= u & -u) maximize(res, bit1[u]);
		return res;
	}

	int get_suff(int u) {
		int res = -inf;
		for (; u <= n; u += u & -u) maximize(res, bit2[u]);
		return res;
	}

	int get(int l, int r) {
		return max(get_pref(l), get_suff(r));
	}

	void update(int i, int val) {
		update_pref(i, val);
		update_suff(i, val);
	}

} tree_row[maxN], tree_col[maxN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("jump.inp", "r", stdin);
	freopen("jump.out", "w", stdout);

	cin >> n >> r >> c;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			pos[a[i][j]].emplace_back(i, j);
		}
	}

	for (int i = 1; i <= n; ++i) tree_row[i] = FendwickTree();
	for (int j = 1; j <= n; ++j) tree_col[j] = FendwickTree();

	tree_row[r].update(c, 1);
	tree_col[c].update(r, 1);

	int ans = 1;

	for (int val = a[r][c] + 1; val < MAX; ++val) {
		for (ii p : pos[val]) {
			int i = p.first;
			int j = p.second;

			int cur = -inf;
			if (i > 1) maximize(cur, tree_row[i - 1].get(j - 2, j + 2));
			if (i < n) maximize(cur, tree_row[i + 1].get(j - 2, j + 2));
			if (j > 1) maximize(cur, tree_col[j - 1].get(i - 2, i + 2));
			if (j < n) maximize(cur, tree_col[j + 1].get(i - 2, i + 2));

			dp[i][j] = cur + 1;

			debug(i, j, dp[i][j]);


			maximize(ans, dp[i][j]) ;
		}

		for (ii p : pos[val]) {
			int i = p.first;
			int j = p.second;

			tree_row[i].update(j, dp[i][j]);
			tree_col[j].update(i, dp[i][j]);
		}
	}

	cout << ans;
}
