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

const int MAXN = 1e6 + 11;
const long long INF = 1e18 + 11;

int n, a[MAXN], x, y, z;
long long prod_z[MAXN], prod_yz[MAXN];

void process(void) {
	cin >> n;
	FORE(i, 1, n) cin >> a[i];
	cin >> x >> y >> z;

	prod_z[n + 1] = -INF;
	FORDE(i, n, 1) prod_z[i] = max(prod_z[i + 1], 1LL * a[i] * z);
	prod_yz[n] = -INF;
	FORDE(i, n - 1, 1) prod_yz[i] = max(prod_yz[i + 1], 1LL * a[i] * y + prod_z[i + 1]);
	long long ans = -INF;
	FORE(i, 1, n - 2) {
		maximize(ans, 1LL * a[i] * x + prod_yz[i + 1]);
	}
	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
