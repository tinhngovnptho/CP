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

#define name "join"

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, Y b) { 
    return a < b ? a = b, 1 : 0; 
}
template<class X, class Y> bool minimize(X &a, Y b) { 
    return a > b ? a = b, 1 : 0; 
}

const int MAXN = 1e6 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 
const int LOG = 60; 

int n, a[MAXN];
int dp[MAXN][LOG + 1];

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    FOR(i, 1, n)  dp[i][0] = i;
    FORD(i, n - 1, 1) {
        FOR(k, 1, LOG) {
            int pre = dp[i][k - 1];
            if (pre == -1) break;
            FOR(j, 0, LOG) if (1ll * a[i] * mask(k - 1) == 1ll * a[pre + 1] * mask(j)) {
                dp[i][k] = dp[pre + 1][j];
                break;
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, n) FOR(j, 0, LOG) if (dp[i][j] != -1) maximize(ans, 1ll * a[i] * mask(j));

    cout << ans;

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
