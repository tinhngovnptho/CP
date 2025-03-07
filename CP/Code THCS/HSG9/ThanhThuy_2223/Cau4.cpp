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
const int mxVal = 1e7 + 11;

bool prime[mxVal];
int l, r;

int tcs(int x) {
	int t = 0;
	while (x) {
		t += x % 10;
		x /= 10;
	}
	return t;
}

void sieve(int n) {
	memset(prime, 1, sizeof prime);
	prime[0] = prime[1] = 0;
	FOR(i, 2, sqrt(n)) if (prime[i]) {
		for (int j = i*i; j <= n; j += i) prime[j] = 0;
	}
}

signed main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	file("Cau4");
	cin >> l >> r;
	sieve(r);
//	FOR(i, 1, r) cout << prime[i] << " " << prime[tcs(i)] << "\n";
	bool check = 0;
	FOR(i, l, r) if (prime[i] && prime[tcs(i)]) cout << i << " ", check = 1;
	if (!check) cout << -1;
}


/**-----------------------------------------------
---------------Author: tinhnopro------------------
---------------While (!Die) Code(); <3------------
-----------------------------------------------**/
