#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
#define FORA(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long

template <class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template <class T> T abs(const T &a) { return a >= 0 ? a : -a; }

ll L, R, T;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> L >> R >> T;

	ll xmax = T / 2 - (T % 2 == 0), xmin = max(L, T - R);

	if (xmax >= T - xmax) xmax--;

	if (xmax > R || xmin >= T - xmin) return cout << 0, 0;

	cout << max(0LL, xmax - xmin + 1);

	return 0;
}
