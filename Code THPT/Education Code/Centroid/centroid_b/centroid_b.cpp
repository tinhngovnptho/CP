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

#define name "centroid_b"

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

int n, k1, k2;
vi adj[MAXN];
int child[MAXN], del[MAXN];

void countChild(int u, int par) {
    child[u] = 1;
    for (int &v : adj[u]) if (v != par && !del[v]) {
        countChild(v, u);
        child[u] += child[v];
    }
}

int findCentroid(int u, int par, int sz) {
    for (int &v : adj[u]) if (v != par && !del[v] && child[v] > sz / 2) {
        return findCentroid(v, u, sz);
    }
    return u;
}

ll solve(int root, int sz) {
    
}

ll CD(int u) {
    countChild(u, u);

    int sz = child[u];

    int root = findCentroid(u, u, sz);
    solve(root, sz);
    
    ll cur = 0;
    for (int &v : adj[u]) if (!del[v]) {
        cur += CD(v);
    }

    return cur;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> k1 >> k2;
    FOR(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
