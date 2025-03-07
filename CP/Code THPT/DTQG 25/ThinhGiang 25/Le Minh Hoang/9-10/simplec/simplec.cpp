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

#define name "simplec"

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

const int MAXN = 1e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

vi adj[MAXN];
vector<ii> bridges;
int n, m; 
int low[MAXN], num[MAXN];
bool used[MAXN];

struct DSU {
    int lab[MAXN];
    
    void reset(void) {
        memset(lab, -1, sizeof lab);
    }

    int find_par(int u) {
        return lab[u] < 0? u : lab[u] = find_par(lab[u]);
    }

    int sz(int u) {
        u = find_par(u);
        if (used[u]) return -1;
        else used[u] = true;
        return -lab[u];
    }

    bool union_set(int u, int v) {
        u = find_par(u);
        v = find_par(v);

        if (u == v) return false;
        
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;

        return true; 
    }
} dsu;

void dfs(int u, int par) {
    static int timeDFS = 0;
    num[u] = low[u] = ++timeDFS;
    
    for (int v : adj[u]) if (v != par) {
        if (!num[v]) {
            dfs(v, u);
            minimize(low[u], low[v]);
            if (low[v] >= num[v]) {
                bridges.push_back({u, v});
            }
        } else minimize(low[u], num[v]);
    }

}

void build_bridges_forest(void) {
    FOR(i, 1, n) if (!num[i]) dfs(i, i);
    dsu.reset();
    for (ii x : bridges) {
        if (!dsu.union_set(x.fi, x.se)) continue;
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
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build_bridges_forest();

    ll res = 0;

    FOR(i, 1, n) {
        int k = dsu.sz(i);
        if (k == -1) continue;
        res += 1ll * k * (k - 1) / 2 - (k - 1);
    }

    cout << res;

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
