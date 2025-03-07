#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<ll, ll>
#define vt vector
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (ll) (x) * (x)
#define FOR(i, a, b) for (__typeof(a) i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (__typeof(a) i = (b), _a = (a); i >= _a; --i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template<class T> bool umin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll oo  = 1e18;
const int MOD = 1e9 + 7;
const int mxN  = 2e5 + 11;
const int mxVal = 1e6 + 11;

vt<int> v;

signed main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	file("Cau3");
	int n, m, x;
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> x;
		if (x < 0) {
			v.push_back(abs(x));
		}
	}
	sort(all(v), greater<int>());
	ll ans = 0;

	FOR(i, 0, min(m, sz(v)) - 1) {
		ans += v[i];
	}

	cout << ans;
}


/**-----------------------------------------------
---------------Author: tinhnopro------------------
---------------While (!Die) Code(); <3------------
-----------------------------------------------**/
