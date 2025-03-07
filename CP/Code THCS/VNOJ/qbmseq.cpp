#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define pii pair<ll, ll>
#define vt vector
#define pub push_back
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (x) * (x)
#define FORC(i, a, b, s) for (__typeof(a) i=(a); (s)>0 ? i<=(b) : i>=(b); i+=(s))
#define FOR(i, a, b) FORC(i, a, b, 1)
#define FORD(i, a, b) FORC(i, a, b, -1)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define tinhnopro signed main

template<class T> bool umin(T& a, const T& b)
{
    return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b)
{
    return a < b ? a = b, 1 : 0;
}

const ll oo  = 1e18;
const int INF = 2e9 + 1e8 + 1e7;
const int MOD = 1e9 + 7;
const int mxN  = 1e4 + 11;

int n, a[mxN];

tinhnopro()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // file("KEK");
        cin >> n;
        FOR(i, 1, n) cin >> a[i];

        int ans = 0, len = 0;
        auto check = [&] (int x)
        {
                int lim = sqrt(2*x);
                return (lim * (lim + 1) / 2 == x || (lim + 1) * (lim + 2) / 2 == x);
        };
        FOR(i, 1, n)
        {
                if (check(a[i]))
                {
                        if (a[i-1] <= a[i])
                                len++;
                        else
                                len = 1;
                }
                else
                        len = 0;
                ans = max(ans, len);
        }
        cout << ans;
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/
