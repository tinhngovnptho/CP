#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<int, int>
#define vt vector
#define pub push_back
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (x) * (x)
#define reset(f, v) memset(f, v, sizeof f)
#define FORC(i, a, b, s) for (__typeof(a) i = (a), _b = (b); (s)>0 ? i<_b : i>_b; i += (s))
#define FORCE(i, a, b, s) FORC(i, a, (s > 0) ? b+1 : b-1, s)
#define FOR(i, a, b) FORC(i, a, b, 1)
#define FORE(i, a, b) FORCE(i, a, b, 1)
#define FORD(i, b, a) FORC(i, a, b, -1)
#define FORDE(i, b, a) FORCE(i, b, a, -1)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template<class T> bool umin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

const ll oo  = 1e18;
const int INF = 1e9 + 1e8 + 1e7;
const int MOD = 1e9 + 7;
const int mxN  = 1e3 + 11;

int n, m, a[mxN], b[mxN], dp[mxN][mxN];

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> m >> n;
        FORE(i, 1, m) cin >> a[i];
        FORE(i, 1, n) cin >> b[i];
        reset(dp, 0);
        FORE(i, 1, m) {
                FORE(j, 1, n) {
                        if (i == 1 || j == 1) {
                                if (a[i] == b[j])
                                        dp[i][j] = 1;
                                else
                                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                                continue;
                        }
                        if (a[i] == b[j])
                                dp[i][j] = dp[i-2][j-2] + 1;
                        else
                                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
        }
        cout << dp[m][n];
}
