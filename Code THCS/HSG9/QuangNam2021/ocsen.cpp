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
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, x, y, a[2001][2001], cnt;

void dfs(int i, int j) {
	a[i][j] = 1;
	REP(k, 4) {
		int ii = i + dx[k], jj = j + dy[k];
		if (ii && ii <= n && jj && jj <= m && !a[ii][jj]) {
			cnt++;
			dfs(ii, jj);
		}
	}
}

void process(void) {
	cin >> n >> m >> x >> y;
	FORE(i, 1, n) FORE(j, 1, m) cin >> a[i][j];
	if (a[x][y]) return void(cout << -1);
	cnt = 1;
	dfs(x, y);
	cout << cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
