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

const int MAXN = 5e5 + 11;

int n, m;
pair<int, int> l[MAXN], d[MAXN];
long long diff[MAXN], ans[MAXN], p[MAXN];

void process(void) {
	cin >> n >> m;
	FORE(i, 1, n) cin >> l[i].fi;
	FORE(i, 1, n) cin >> l[i].se;
	FORE(i, 1, m) {
		cin >> d[i].fi;
		d[i].se = i;
	}

	sort(d + 1, d + m + 1);
	FORE(i, 1, m) p[i] = d[i].fi;
	FORE(i, 1, n) {
		int left = max(1, l[i].fi - l[i].se);
		int right = l[i].fi + l[i].se;
		int L = lower_bound(p + 1, p + m + 1, left) - p;
		int R = upper_bound(p + 1, p + m + 1, right) - p - 1;
		diff[L]++;
		diff[R + 1]--;
	}
	FORE(i, 1, m) {
		diff[i] += diff[i - 1];
		ans[d[i].se] = diff[i];
	}
	FORE(i, 1, m) cout << ans[i] << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("light");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
