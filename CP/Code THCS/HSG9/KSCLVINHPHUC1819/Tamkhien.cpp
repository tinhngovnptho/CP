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
#define ull unsigned long long

template<class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template<class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template<class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; }

int a[3], b[3];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	ll sum = 0, P = 1e18;

	FOR(i, 0, 2) {
		cin >> a[i];
		sum += a[i];
	}
	FOR(i, 0, 2) {
		cin >> b[i];
		sum += b[i];
	}

	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			ll tmp = sum - a[i] - b[j] + abs(a[i] - b[j]);
			P = min(P, tmp);
		}
	}

	cout << P;
}
