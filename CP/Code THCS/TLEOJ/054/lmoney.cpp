#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;
typedef __int128_t int128;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e5 + 11;

int n, m, q, s[MAXN], c[MAXN], l[MAXN], r[MAXN];
int64 sum_s[MAXN], sum_c[MAXN];

int first[MAXN][200], last[MAXN][200];

namespace Sub1 {
	bool check(void) {
		FORE(i, 1, n) if (s[i] != 0) return false;
		return true;
	}
	void solve(void) {
		FORE(i, 1, q) {
			cout << sum_c[r[i]] - sum_c[l[i] - 1] << "\n";
		}
	}
};

namespace Sub3 {
	bool check(void) {
		FORE(i, 1, q) if (l[i] != 1) return false;
		return true;
	}
	int pos[MAXN], ans[MAXN];
	void solve(void) {
		memset(pos, -1, sizeof pos);
		pos[sum_s[0]] = 0;
		FORE(i, 1, n) {
			ans[i] = ans[i - 1];
			if (pos[sum_s[i]] != -1) {
				int j = pos[sum_s[i]];
				maximize(ans[i], sum_c[i] - sum_c[j]);
			} else pos[sum_s[i]] = i;
		}
		FORE(i, 1, q) cout << ans[r[i]] << "\n";
	}
};

namespace Sub2 {
	bool check(void) {
		return n <= 500 && q <= 500;
	}
	void solve(void) {
		FORE(i, 1, q) {
			int L = l[i], R = r[i];
			int64 ans = 0;
			FORE(u, L - 1, R) FORE(v, u + 1, R) {
				if (sum_s[u] == sum_s[v]) maximize(ans, sum_c[v] - sum_c[u]);
			}
			cout << ans << "\n";
		}
	}
};

void process(void) {
	cin >> n >> m >> q;
	FORE(i, 1, n) {
		cin >> s[i];
		sum_s[i] = (sum_s[i - 1] + s[i]) % m;
	}
	FORE(i, 1, n) {
		cin >> c[i];
		sum_c[i] = sum_c[i - 1] + c[i];
	}
	FORE(i, 1, q) cin >> l[i] >> r[i];
	if (Sub1::check()) return Sub1::solve();
	if (Sub3::check()) return Sub3::solve();
	if (Sub2::check()) return Sub2::solve();

	REP(j, m) first[n + 1][j] = n + 1;
	FORDE(i, n, 0) REP(j, m) {
		first[i][j] = first[i + 1][j];
		if (sum_s[i] == j) first[i][j] = i;
	}

	REP(j, m) last[0][j] = -1;
	FORE(i, 1, n) REP(j, m) {
		last[i][j] = last[i - 1][j];
		if (sum_s[i] == j) last[i][j] = i;
	}

	FORE(i, 1, q) {
		int L = l[i], R = r[i];
		int64 ans = 0;
		REP(j, m) if (first[L - 1][j] != n + 1 && last[R][j] != -1) {
			int v = last[R][j], u = first[L - 1][j];
			maximize(ans, sum_c[v] - sum_c[u]);
		}
		cout << ans << "\n";
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("lmoney");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
