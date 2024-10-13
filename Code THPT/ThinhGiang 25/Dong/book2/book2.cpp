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

#define name "book2"

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

const int MAXN = 1e4 + 11;
// const int MOD = 1e9 + 7; 
const ll INFF = 1e18 + 11; 

int n, k;
vi a, sum;
vector<vector<ll> > dp, best;

ll cost(int i, int j) {
    return 1ll * (sum[j] - sum[i - 1]) * (sum[j] - sum[i - 1]);
}

void opt_dp(int i, int l, int r, int opt_l, int opt_r) {
    if (l > r) return ;
    int mid = (l + r) >> 1;
    dp[i][mid] = INFF;
    FOR(j, opt_l, opt_r) {
        int new_cost = cost(j + 1, mid);
        if (minimize(dp[i][mid], dp[i - 1][j] + cost(j + 1, mid))) {
            best[i][mid] = j;
        }
    }

    opt_dp(i, l, mid - 1, opt_l, best[i][mid]);
    opt_dp(i, mid + 1, r, best[i][mid], opt_r);
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> k;
    a.assign(n + 1, 0);
    sum.assign(n + 1, 0);
    dp.assign(n + 1, vector<ll>(n + 1, 0));
    best.assign(n + 1, vector<ll>(n + 1, 0));

    FOR(i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    FOR(i, 1, n) dp[1][i] = cost(1, i);
    FOR(i, 2, k) opt_dp(i, 1, n, 1, n);

    cout << dp[k][n]; 
    

    cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
