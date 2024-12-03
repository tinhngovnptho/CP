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

#define name "tnt"

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, Y b) { return a < b ? a = b, 1 : 0; }
template<class X, class Y> bool minimize(X &a, Y b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 8e3 + 11; 
// const int MOD = 1e9 + 7; 
// const int INF = 1e9 + 11; 
const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;

int n, m;
ll a[MAXN];
ll dp[MAXN][811];

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) a[i] += a[i - 1];

    FOR(i, 0, n) FOR(j, 0, m) dp[i][j] = INFF;

    FOR(i, 1, n) dp[i][1] = 1LL * a[i] * i;
    FOR(j, 2, m) {
        FOR(i, 1, n) {
            FOR(k, 1, i - 1) if (dp[k][j - 1] != INFF) {
                minimize(dp[i][j], dp[k][j - 1] + 1LL * (a[i] - a[k]) * (i - k));
            }
        }
    }

    cout << dp[n][m] << el;

    return 0;
}
