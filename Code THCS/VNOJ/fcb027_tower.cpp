#include <bits/stdc++.h>
using namespace std;

#define NAME ""
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (ll) (x) * (x)
#define FOR(i, a, b) for (__typeof(a) i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (__typeof(b) i = (b); i >= (a); --i)
#define FORC(i, a, b, s) for (__typeof(a) i = (a); i <= (b); i += (s))

template <class T> bool umin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template <class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


signed main(void) {
        cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
        if (fopen(NAME ".inp", "r"))
                freopen(NAME ".inp", "r", stdin), freopen(NAME ".out", "w", stdout);

int tests; cin >> tests; while (tests--) {
                ll n;
                cin >> n;
                ll lim = sqrtl(2*n);
                bool ans = lim * (lim + 1) / 2 == n;
                cout << (ans ? "YES" : "NO") << endl;
        }
}

/**-----------------------------------------
-------------Author: tinhnopro -------------
-----------From: NQB with luv <3 -----------
---------//--------NVT---------//-----------
-----------------------------------------**/
