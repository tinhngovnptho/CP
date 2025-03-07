// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MAXN = 1e5 + 11;
const long long INF = 1e18 + 11;

int n, k;
long long a[MAXN], dp[MAXN], seg[4 * MAXN];

void update(int id, int l, int r, int pos, long long val) {
	if (l > pos || pos > r) return ;
	if (l == r) {
		seg[id] = val;
		return ;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

long long query(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return -INF;
	if (u <= l && r <= v) return seg[id];
	int mid = l + r >> 1;
	return max(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	cin >> n >> k;
	FORE(i, 1, n) cin >> a[i];

	dp[n] = a[n];
	update(1, 1, n, n, dp[n]);

	FORDE(i, n - 1, 1) {
		dp[i] = max(query(1, 1, n, i + 1, min(i + k, n)), 0LL) + a[i];
//		cout << dp[i] << " " << query(1, 1, n, min(n, i + 1), min(i + k, n)) << "\n";
		update(1, 1, n, i, dp[i]);
	}

	cout << max(0LL, *max_element(dp + 1, dp + 1 + n));

	return 0;
}
