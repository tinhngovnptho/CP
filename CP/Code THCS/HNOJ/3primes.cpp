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

#define MAX_N	1000011

bool prime[MAX_N];

vector<int> v;

ll n;

void sieve(void) {
	memset(prime, -1, sizeof prime);
	FOR(i, 2, sqrt(MAX_N)) if (prime[i]) {
		FOR(j, i, MAX_N / i) prime[i*j] = 0;
	}
	FOR(i, 2, MAX_N) if (prime[i]) {
		v.push_back(i);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;

	sieve();
	ll ans = 0;

	FOR(i, 0, sz(v)-3) {
		ll k = 1LL * v[i] * v[i+1] * v[i+2];
		if (k <= n) umax(ans, k);
	}

	cout << ans;

	return 0;
}
