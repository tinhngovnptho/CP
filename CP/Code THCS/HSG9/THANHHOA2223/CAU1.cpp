#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, b, a) for (int i = (b); i >= (a); i--)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long

template<class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template<class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template<class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; }

ll a, b, c;

void solve(void) {
	cin >> a >> b >> c;
	if (a <= 0 || b <= 0 || c <= 0) return void(cout << "0\n");
	if (a + b + c != 180) return void(cout << "0\n");
	if (a == 90 || b == 90 || c == 90) return void(cout << "VUONG\n");
	if (a > 90 || b > 90 || c > 90) return void(cout << "TU\n");
	cout << "NHON\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	int tests; cin >> tests;

	while (tests--) {
		solve();
	}
}
