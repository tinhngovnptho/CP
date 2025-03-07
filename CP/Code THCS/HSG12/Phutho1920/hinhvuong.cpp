#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	int n, x; cin >> n;
	vector<int> d(n, 1e9+11);
	int ans = 0;
	FOR(i, 1, n) {
		cin >> x;
		int idx = upper_bound(ALL(d), x) - d.begin();
		d[idx] = x;
		ans = max(ans, idx+1);
	}

	cout << ans;

	return 0;
}

