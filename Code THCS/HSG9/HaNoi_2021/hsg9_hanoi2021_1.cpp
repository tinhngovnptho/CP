#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define vt vector
#define pub push_back
#define ii pair<int, int>
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template<class T> bool umin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

const ll oo  = 1e18;
const int INF = 1e9 + 1e8 + 1e7;
const int mxN  = 1e6 + 11;

ll a, b, c, MOD;

ll mul(ll a, ll b) {
    int sign = b < 0 + a < 0;
    a = abs(a); b = abs(b);
    ll res = 0;
    while(b) {
        if (b & 1)
            res = (res + a % MOD) % MOD;
        a = 2 * a % MOD;
        b /= 2;
    }
    if (sign == 1) res = -res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    file("MAXPROD");

    cin >> a >> b >> c >> MOD;
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (b > 0)
        cout << mul(b, c);
    else
        cout << mul(b, a);
}
