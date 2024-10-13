#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
#define FORA(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(x) (int) (x).size()
#define ll long long
#define ld long double
#define ull unsigend long long
#define fi first
#define se second

#define NAME	""

template <class X, class Y> bool umin(X &a, const Y &b) { return  a > b ? a = b, 1 : 0; }
template <class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(T& a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template <class T> T abs(T a) { return a >= 0 ? a : -a; }

int x, y, a, b;

int gcd(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	if (fopen(NAME".inp", "r")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}

	cin >> x >> y >> a >> b;

	int l = lcm(x, y);

	cout << b / l - (a-1) / l;

	return 0;
}
