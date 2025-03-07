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

const int MAXN = 1e3+11;

int n, k, x, d;
vector<int> v;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> k;
	v.push_back(-1e9-11);
	FOR(i, 1, n) {
		cin >> x;
		if (i == k) {
			d = x;
		} else v.push_back(x);
	}
	sort(ALL(v));
	long long res = 0;

	if (k == 1 || k == n) {
		FOR(i, 2, n-1) res += abs(v[i] - v[i-1]);
		res += min(abs(d - v[1]), abs(d - v.back()));
	} else {
		FOR(i, 2, k-1) res += abs(v[i] - v[i-1]);
		res += min(abs(d - v[1]), abs(d - v[k-1]));
		FOR(i, k+1, n-1) res += abs(v[i] - v[i-1]);
//		cout << res << "\n";
		res += min(abs(d - v[k]), abs(d - v.back()));
	}

	cout << res;

	return 0;
}
