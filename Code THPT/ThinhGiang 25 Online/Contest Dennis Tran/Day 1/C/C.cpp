#include<bits/stdc++.h>

// Author: Tinhnopro (a.k.a NVT)

using namespace std;

#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define ld long double
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define ONBIT(i, mask) (mask | MASK(i))
#define OFFBIT(i, mask) mask & ~(MASK(i))

#define int long long 

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 1e5 + 11;
const int MOD = 1e9 + 7;
int n, k, dp[MAXN][111];

void process(void) {
    cin >> n >> k;
    dp[0][0] = 1;
    int res = 1;
    FOR(i, 1, n) {
        res = res * 2;
        res %= MOD;
    }
    FOR(i, 1, n) {
        FOR(j, 0, k - 1) {
            dp[i][0] += dp[i - 1][j];
            dp[i][0] %= MOD;
        }
        FOR(j, 1, k - 1) {
            dp[i][j] = dp[i - 1][j - 1];
        }
    }
    int ans = 0;
    FOR(i, 0, k - 1) {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << (res - ans + 2 * MOD) % MOD;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "C"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
