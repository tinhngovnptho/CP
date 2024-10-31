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

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 3e5 + 11;

int n, a[MAXN];

namespace Sub12 { 
    int dp[411][411];

    void solve(void) {
        FOR(i, 1, n) dp[i][i] = a[i];
        FOR(len, 2, n) {
            FOR(l, 1, n - len + 1) {
                int r = l + len - 1;
                dp[l][r] = -1;
                FOR(mid, l, r - 1) if (dp[l][mid] == dp[mid + 1][r]) {
                    maximize(dp[l][r], dp[l][mid] + 1);
                }
            }
        } 
        int ans = -1;
        FOR(i, 1, n) FOR(j, i, n) maximize(ans, dp[i][j]);
        cout << ans; 
    }
}

namespace Sub3 {
    int dp[MAXN][71];

    void solve(void) {
        memset(dp, -1, sizeof dp);

        int ans = -1;

        FOR(val, 1, 70) {
            FOR(l, 1, n) {
                if (val == a[l]) {
                    dp[l][val] = l;
                } else if (dp[l][val - 1] != -1 && dp[dp[l][val - 1] + 1][val - 1] != -1) {
                    dp[l][val] = dp[dp[l][val - 1] + 1][val - 1];
                }
                if (dp[l][val] != -1) maximize(ans, val);
            }
        } 
        cout << ans; 
    }
}


void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    Sub3::solve();
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "B"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
