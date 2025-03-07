/**------------------------------------------
------Author: Tinhnopro (Tinh nop) ----------
---------From: CHV with luv <3 --------------
---------Value = Live + Love ---------------- 
------------------------------------------**/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second

#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define pb push_back

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

#define Mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | Mask(i))
#define offbit(i, mask) (mask & ~(Mask(i)))
#define cntbit(x) __builtin_popcountll(x)
#define Log2(x) (63 - __builtin_clzll(x))

using namespace std;

using db = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;

template<class X, class Y> bool maximize(X &a, Y b) { 
    return a < b ? a = b, 1 : 0; 
}

template<class X, class Y> bool minimize(X &a, Y b) { 
    return a > b ? a = b, 1 : 0; 
}

// const int dx[8] = {+1, -1, +0, +0, +1, -1, +1, -1}, dy[8] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int INF = 1e9 + 11, MAXN = 5e5 + 11, MOD = 1e9 + 7; 
const int64_t INFF = (int64_t) 1e18 + 7;
//_______________________________________________________________________________________________
int n, a[MAXN], b[MAXN];
int64_t dp[MAXN][2];

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    FOR(i, 1, n) dp[i][0] = dp[i][1] = -INFF; 

    FOR(i, 1, n) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i] * b[i];
        if (a[i] == 0 || a[i - 1] == 0 && i > 1) {
            dp[i][1] = max(dp[i - 2][0], dp[i - 2][1])  + a[i - 1] * b[i] + a[i] * b[i - 1];
        }
    } 
    cout << max(dp[n][0], dp[n][1]);
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    #define name "game"
    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin); 
        freopen(name".out", "w", stdout);
    }
    //____________________________________________________
    // int t; cin >> t; while (t--)
    process();

    cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
    return 0;
}
