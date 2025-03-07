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

int cnt[256], k;
string s;

bool check(void) {
	return cnt['A'] < k || cnt['C'] < k || cnt['V'] < k;
}

void process(void) {
	cin >> k >> s;
	int n = s.size(); s = " " + s;
	int res = 2e5 + 11;
	for (int l = 1, r = 0; l <= n; --cnt[s[l++]]) {
		while (r < n && check()) ++cnt[s[++r]];
//		cout << l << " " << r << "\n";
		if (check()) break;
		int t = cnt['A'] + cnt['V'] + cnt['C'] -  3 * k;
		minimize(res, t);
	}
	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("olp_ct20_vca");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
