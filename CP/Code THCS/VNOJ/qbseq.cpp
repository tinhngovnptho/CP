#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
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

template<class T> bool umin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

const ll oo  = 1e18;
const int INF = 2e9 + 1e8 + 1e7;
const int MOD = 1e9 + 7;
const int mxN  = 1e3 + 11, mxK = 55;

int a[mxN], dp[mxN][mxK], n, k;

tinhnopro() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
//        file("KEK");
        cin >> n >> k;
        FOR(i, 1, n) {
                cin >> a[i];
                a[i] %= k;
        }
        memset(dp[1], -0x3f, sizeof dp[1]);
        dp[1][0] = 0;
        dp[1][a[1]] = 1;
        FOR(i, 2, n) FOR(j, 0, k-1) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][(j-a[i]+k) % k] + 1);
        }
        cout << dp[n][0];
}
