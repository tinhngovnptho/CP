#include <bits/stdc++.h>
using namespace std;

#define NAME "ShenYun"
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair <int, int>
#define vi vector <int>
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (__typeof(a) i = (a); i < (b); ++i)
#define down(i, b, a) for (__typeof(b) i = (b)-1; i >= (a); --i)
#define fora(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

template <class T> bool umin(T& a, const T& b) { return  a > b ? a = b, 1 : 0; }
template <class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(T& a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }

ll N, x, y;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	if (fopen(NAME ".inp", "r")) {
		assert(freopen(NAME ".inp", "r", stdin));
		assert(freopen(NAME ".out", "w", stdout));
	}

	cin >> N >> x >> y;

	cout << N / lcm(x, y);
}
