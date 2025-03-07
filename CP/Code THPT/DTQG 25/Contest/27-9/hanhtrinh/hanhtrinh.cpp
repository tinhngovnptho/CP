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

int n, d[MAXN], x[MAXN], dp[MAXN];

namespace Sub1 {
    void solve(void) {
        FORD(i, n - 1, 1) {
        if (d[i] == 0) continue;
            int mx = (n - i) / d[i];
            minimize(mx, x[i]);
            FOR(j, 1, mx) {
                int t = i + j * d[i];
                dp[i] += dp[t];
                dp[i] %= MOD;
            }
        }
        cout << dp[1];
    }
}

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> d[i] >> x[i];
    FOR(i, 1, n) dp[i] = 1;
    if (n <= 1000) return void(Sub1::solve());
    vector<int> suff;
    suff.resize(n + 2);
    suff[n + 1] = 0;
    suff[n] = 1;
    FORD(i, n - 1, 1) {
        if (d[i] == 0) {
            suff[i] = dp[i] + suff[i + 1];
            suff[i] %= MOD;
            continue;
        }
        int mx = (n - i) / d[i];
        minimize(mx, x[i]);
        dp[i] += (suff[i + 1 * d[i]] - suff[i + mx * d[i] + 1] + 2 * MOD) % MOD;
        dp[i] %= MOD;
        suff[i] = dp[i] + suff[i + 1];
        suff[i] %= MOD;
    }
    cout << dp[1];
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "hanhtrinh"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
