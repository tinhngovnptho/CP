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
const int INF = 1e9 + 1e8 + 1e7;
const int MOD = 1e9 + 7;
const int mxN  = 3e4 + 11;

vt<int> t[mxN];
int dp[mxN], n;

tinhnopro()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // file("KEK");
        cin >> n;
        FOR(i, 1, n)
        {
                int l, r;
                cin >> l >> r;
                t[r].pub(l);
        }
        dp[0] = 0;
        FOR(i, 1, mxN-1)
        {
                dp[i] = dp[i-1];
                FOR(j, 0, sz(t[i]) - 1)
                {
                     umax(dp[i], i - t[i][j] + dp[t[i][j]]);
                }
        }
        cout << dp[mxN-1];
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|
12
1 2
3 5
0 4
6 8
7 13
4 6
9 10
9 12
11 14
15 19
14 16
18 20
--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|
16
--------------------------------------------------|
==================================================+
*/
