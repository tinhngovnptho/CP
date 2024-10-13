#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= (b); ++i)
#define FORA(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int) (x).size()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) {
	return a < b ? a = b, 1 : 0;
}

template <class X, class Y> bool minimize(X &a, const Y &b) {
	return a > b ? a = b, 1 : 0;
}

const int MAXN = 1e5+11;

int n, k, a[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("QHD.inp", "r", stdin);
	freopen("QHD.out", "w", stdout);

	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];

	sort(a+1, a+1+n);

	int d = 1, ans = 0;

	FOR(i, 2, n) {
		if (a[i] - a[i-1] > k) {
			maximize(ans, d);
			d = 1;
		} else d++;
	}

	maximize(ans, d);

	cout << ans;

	return 0;
}
