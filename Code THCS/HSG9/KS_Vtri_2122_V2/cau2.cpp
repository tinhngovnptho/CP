#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
#define FORA(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(x) (int) (x).size()
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second

#define NAME	""

template <class X, class Y> bool umin(X &a, const Y &b) { return  a > b ? a = b, 1 : 0; }
template <class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(T& a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template <class T> T abs(T a) { return a >= 0 ? a : -a; }

ll sum_of(int x) {
	return 1LL * x * (x + 1) / 2;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	if (fopen(NAME".inp", "r")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}

	int n;
	cin >> n;

	ll ans = 3 * sum_of(n/3);
	ans += 5 * sum_of(n/5);
	ans -= 2 * 15 * sum_of(n/15);

	cout << ans;

	return 0;
}
