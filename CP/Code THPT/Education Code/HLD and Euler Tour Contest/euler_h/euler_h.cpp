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

const int MAXN = 2e5 + 11;
int n, q, v[MAXN], sz[MAXN], par[MAXN], depth[MAXN];
int chainHead[MAXN], chainID[MAXN], pos[MAXN], a[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int parent) {
    sz[u] = 1;
    for (int &v : adj[u]) if (v != parent) {
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];    
    }
}

int curChain = 1, curPos = 1;

void HLD(int u, int parent) {
    if (!chainHead[curChain]) {
        chainHead[curChain] = u;
    }
    chainID[u] = curChain;
    pos[u] = curPos;
    a[curPos] = u;
    curPos++;

    int nxt = 0;
    for (int &v : adj[u]) if (v != parent) {
        if (nxt == 0 || sz[v] > sz[nxt]) nxt = v;
    }
    if (nxt) HLD(nxt, u);
    for (int &v : adj[u]) if (v != parent && v != nxt) {
        curChain++;
        HLD(v, u);
    }
}

int LCA(int u, int v) {
    while (chainID[u] != chainID[v]) {
        if (chainID[u] > chainID[v]) {
            u = par[chainHead[chainID[u]]];
        } else {
            v = par[chainHead[chainID[v]]];
        }
    }
    if (depth[u] < depth[v]) return u;
    return v; 
}

int seg[4 * MAXN];

void build(int id, int l, int r) { 
    if (l == r) {
        return void(seg[id] = v[a[l]]);
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return ;
    if (l == r) {
        seg[id] = val;
        return ;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val); 
    update(id << 1 | 1, mid + 1, r, pos, val);
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]); 
}

int getmax(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -1e9;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return max(getmax(id << 1, l, mid, u, v), 
            getmax(id << 1 | 1, mid + 1, r, u, v));
}

void Update(int u, int val) {
    update(1, 1, n, pos[u], val);
}

int Query(int u, int v) {
    int lca = LCA(u, v);
    int ans = -1e9;
    while (chainID[u] != chainID[lca]) {
        int head = chainHead[chainID[u]];
        maximize(ans, getmax(1, 1, n, pos[head], pos[u]));
        u = par[head];
    }
    while (chainID[v] != chainID[lca]) {
        int head = chainHead[chainID[v]];
        maximize(ans, getmax(1, 1, n, pos[head], pos[v]));
        v = par[head];
    }
    if (depth[u] < depth[v]) {
        maximize(ans, getmax(1, 1, n, pos[u], pos[v]));
    } else maximize(ans, getmax(1, 1, n, pos[v], pos[u]));
    return ans; 
}

void process(void) {
    cin >> n >> q;
    FOR(i, 1, n) cin >> v[i];
    FOR(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    dfs(1, 1);
    HLD(1, 1);
    build(1, 1, n);
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) Update(x, y);
        else cout << Query(x, y) << " ";
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "euler_h"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
