// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define all(v) (v).begin(), (v).end()

#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "d13candyb4"

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<ll>;

template<class X, class Y> bool maximize(X &a, Y b) { 
    return a < b ? a = b, 1 : 0; 
}
template<class X, class Y> bool minimize(X &a, Y b) { 
    return a > b ? a = b, 1 : 0; 
}

const int MAXN = 1e5 + 11; 
// const int MOD = 1e9 + 7; 
// const int INF = 1e9 + 11; const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;
// const int BLOCK = 330;

int n, k, m, dp[MAXN][350];

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> k >> m; 

    // FOR(i, 1, n) {
    //     dp[i][i] = 1;
    //     FORD(j, i - 1, 0) {
    //         dp[i][j] = dp[i][j + 1];
    //         if (j > 0) dp[i][j] += dp[i - j][j + k + 1];
    //         dp[i][j] %= m;
    //     }
    // }

    int sqrt_n = sqrt(n);
    dp[0][0] = 1;
    int ans = 0;
    FOR(x, 1, sqrt_n) {
        // int s = n - x * (x - 1) / 2;
        FOR(j, 1, n) {
            if (j >= x) dp[j][x] = dp[j - x][x];
            if (j - 1 - (x - 1) * (k + 1) >= 0) dp[j][x] += dp[j - 1 - (x - 1) * (k + 1)][x - 1];
            dp[j][x] %= m;
        }
        if (x > 1) ans += dp[n][x];
        ans %= m;
    }

    cout << ans; 
    
    return 0;
}
