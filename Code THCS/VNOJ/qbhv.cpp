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
const int mxN  = 1e6 + 11;

vt<string> ans;
string s;

bool nextP()
{
        FORD(i, sz(s)-2, 0)
        {
                if (s[i] < s[i+1])
                {
                        FORD(j, sz(s)-1, i+1) if (s[j] > s[i])
                        {
                                swap(s[j], s[i]);
                                FOR(i1, i+1, sz(s)-1)
                                {
                                        FOR(j1, i1+1, sz(s)-1) if (s[i1] > s[j1])
                                        {
                                                swap(s[i1], s[j1]);
                                        }
                                }
                                ans.pub(s);
                                return true;
                        }
                }
        }
        return false;
}

tinhnopro()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // file("KEK");
        cin >> s;
        sort(all(s));
        ans.pub(s);
        while (nextP());
        cout << sz(ans) << "\n";
        FOR(i, 0, sz(ans)-1) cout << ans[i] << "\n";
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
