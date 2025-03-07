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

int n, x, a[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	cin >> n >> x;
	FORE(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = -1;
	FORE(i, 1, n) {
		int l = i + 1, r = n, res = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] <= x - a[i]) {
				res = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		if (res) maximize(ans, a[res] + a[i]);
	}

	cout << ans;

	return 0;
}
