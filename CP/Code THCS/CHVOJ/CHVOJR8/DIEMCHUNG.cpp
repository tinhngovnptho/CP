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

const int MAXN = 1e6 + 7;

int n, k, l, r, d[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("DIEMCHUNG.inp", "r", stdin);
	freopen("DIEMCHUNG.out", "w", stdout);

	cin >> n >> k;
	memset(d, 0, sizeof(d));
	FOR(i, 1, n) {
		cin >> l >> r;
		d[l]++;
		d[r+1]--;
	}

	FOR(i, 1, MAXN-1) d[i] += d[i-1];

	int ans = 0;
	FOR(i, 1, MAXN-1) if (d[i] == k) {
		ans++;
	}
	cout << ans;

	return 0;
}
