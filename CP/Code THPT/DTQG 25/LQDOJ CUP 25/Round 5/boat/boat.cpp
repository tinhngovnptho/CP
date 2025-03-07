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

#define name "boat"

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

const int MAXN = 5e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int n, m, t;
vi adj[MAXN];
ii boat[MAXN];
map<ii, int> mp;
int dp[MAXN];

namespace Sub2 {
    bitset<(int) 1e4 + 11> bs[(int) 1e4 + 11];
    void solve(void) {
        FOR(i, 1, m) {
            int u, v; cin >> u >> v;
            bs[u][v] = bs[v][u] = 1;
        } 

        FOR(i, 1, t) {
            int u, v; cin >> u >> v;
            boat[i] = {u, v};
        }

        int ans = -1; 

        FOR(i, 1, n) {
            dp[i] = 1;
            FOR(j, 1, i - 1) if (boat[j].se == boat[i].fi || bs[boat[j].se][boat[i].fi] == 1) {
                maximize(dp[i], dp[j] + 1); 
            }
            maximize(ans, dp[i]);
        }

        cout << ans;
    }
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> m >> t;
    if (n <= 1e4) {
        return Sub2::solve(), 0;
    }
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        mp[{u, v}] = 1;
        mp[{v, u}] = 1;
    } 

    FOR(i, 1, t) {
        int u, v; cin >> u >> v;
        boat[i] = {u, v};
    }

    int ans = -1; 

    FOR(i, 1, n) {
        dp[i] = 1;
        FOR(j, 1, i - 1) if (boat[j].se == boat[i].fi || mp.find({boat[j].se, boat[i].fi}) != mp.end()) {
            maximize(dp[i], dp[j] + 1); 
        }
        maximize(ans, dp[i]);
    }

    cout << ans;

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
