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
int n, S, a[MAXN];

struct FenwickTree {
	int bit[2*MAXN+11], n;

	FenwickTree(int _n) {
		n = _n;
		memset(bit, 0, sizeof bit);
	}

	int query(int u) {
		int res = 0;
		for ( ; u; u -= u & -u) res += bit[u];
		return res;
	}

	void update(int u) {
		for ( ; u <= 2 * MAXN; u += u & -u) bit[u]++;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("kmedian");
	cin >> n >> S;
	FORE(i, 1, n) {
		cin >> a[i];
		a[i] = a[i] >= S ? 1 : -1;
	}
	FenwickTree t(n);

	int prefix = 0;
	long long ans = 0;
	t.update(0 + MAXN);
	FORE(i, 1, n) {
		prefix += a[i];
		ans += t.query(prefix + MAXN);
//		cout << prefix << " " << ans << "\n";
		t.update(prefix + MAXN);
	}

	cout << ans;

	return 0;
}
