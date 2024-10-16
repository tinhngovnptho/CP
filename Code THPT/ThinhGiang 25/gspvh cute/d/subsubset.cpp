// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()
#define szv(v) ((int)(v).size())
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "subsubset"

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

template<class T> using vector2d = vector<vector<T>>;

const int MAXN = 6e3 + 11; // const int MAX = 1e6 + 11;
const int MOD = 998244353;
// const int INF = 1e9 + 11; 
// const ll INFF = 1e18 + 11; 

int n, m, dp[MAXN][2], c[MAXN];

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void solve(void) {
    cin >> n >> m;
    FOR(i, 1, n) cin >> c[i];
    dp[0][0] = 1;

    FOR(i, 1, n) {
        FORD(j, m, 0) FORD(k, 1, 0) {
            add(dp[j][1], dp[j][k]);
            if (j + c[i] <= m) add(dp[j + c[i]][k], dp[j][k]);
        }
    }

    int res = 0;
    FOR(j, 0, m) add(res, dp[j][1]);
    cout << res;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    // int t; cin >> t; while (t--)
    solve();

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
