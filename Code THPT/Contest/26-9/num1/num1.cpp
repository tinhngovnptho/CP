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

const int MAXN = 1e5 + 11;
const int MOD = 1e9 + 7; 

int n, dp[MAXN][13];

int calc(int id, int mod) {
    if (id == n) {
        return mod == 0;
    }
    if (~dp[id][mod]) return dp[id][mod];
    int res = 0;
    FOR(i, 0, 9) if (i != 3 && i != 1) {
        res += calc(id + 1, (mod * 10 + i) % 13);
        res %= MOD; 
    }
    return dp[id][mod] = res;
}

void process(void) {
    cin >> n;
    int ans = 0;
    memset(dp, -1, sizeof dp);
    FOR(i, 2, 9) if (i != 3) {
        ans += calc(1, i);
        ans %= MOD;
    }
    cout << ans; 
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "num1"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
