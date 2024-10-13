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

const int MAXN = 2e5 + 11, INF = 1e9 + 11;

int cnt[MAXN][26], d[MAXN][26], mind[MAXN][26];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("matdo");
	string s; cin >> s;
	int n = s.size(); s = " " + s;

	FORE(i, 1, n) REP(c, 26) {
		cnt[i][c] = cnt[i - 1][c] + (s[i] == c + 'a');
		d[i][c] = 2 * cnt[i][c] - i;
		mind[i][c] = min(mind[i - 1][c], d[i][c]);
	}

	int ans = 0;

	FORE(i, 1, n) {
		int idx = INF;
		REP(c, 26) {
			int l = 0, r = i - 1, res = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				d[i][c] > mind[mid][c] ? res = mid, r = mid - 1 : l = mid + 1;
			}
			if (res != -1) minimize(idx, res);
		}
		if (idx != INF) maximize(ans, i - idx);
	}

	cout << ans;

	return 0;
}
