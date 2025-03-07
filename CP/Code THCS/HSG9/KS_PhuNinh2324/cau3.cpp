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

const int MAXN = 1e5 + 11, INF = 1e6 + 11;
int a[MAXN], prefix[MAXN], suffix[MAXN], n;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("cau3");
	cin >> n;
	FORE(i, 1, n) cin >> a[i];

	prefix[1] = 1;
	FORE(i, 2, n) {
		if (a[i] <= a[i - 1]) {
			prefix[i] = 1;
		} else prefix[i] = prefix[i - 1] + 1;
	}
	prefix[n] = 1;
	FORDE(i, n - 1, 1) {
		if (a[i] <= a[i + 1]) {
			suffix[i] = 1;
		} else suffix[i] = suffix[i + 1] + 1;
	}
	int ans = 0;
	FORE(i, 1, n) {
//		cout << prefix[i] << " " << suffix[i] << "\n";
		maximize(ans, prefix[i] + suffix[i] - 1);
	}

	cout << ans;

	return 0;
}
