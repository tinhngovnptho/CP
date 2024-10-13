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

#define name "binpar"

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
const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

ll n;
map<ll, int> dp;

int solve(ll x) {
    if (x == 1) return 0;
    if (dp.find(x) != dp.end()) return 0;
    int res = 1;
    FORD(bit, 63, 0) if (getbit(bit, x)) {
        if (x == mask(bit)) {
            res += 2 * solve(mask(bit - 1));
            res %= MOD;
            continue;
        }
        res += solve(mask(bit));
        res %= MOD; 
    }
    return dp[x] = res; 
}

void solve(void) {
    cin >> n;
    cout << solve(n) << el;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    dp[1] = 1;
    // int t; cin >> t; while (t--) {
        solve();
    // }

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
