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

const int MAXN = 2005;

int n, m, d[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	cin >> n >> m;
	for (int x, r, i = 0; i < m; ++i) {
		cin >> x >> r;
		int l1 = x + r > n ? n : x + r;
		int l2 = x - r <= 0 ? 1 : x - r;
//		cout << l1 << " " << l2 << "\n";
		d[l1 + 1]--;
		d[l2]++;
	}

	int res = 0;

	FORE(i, 1, n) {
		d[i] += d[i - 1];
		if (d[i]) res++;
	}

	cout << res;

	return 0;
}
