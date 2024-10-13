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
#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((i) & MASK(x))
#define ONBIT(x, i) ((i) | MASK(x))
#define OFFBIT(x, i) ((i) & ~MASK(x))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 1e5 + 11;
const int LOG = 25;

struct Node {
    int v, w;
    Node(int _v, int _w) : v(_v), w(_w) {}
};

int n, par[MAXN][LOG + 1], depth[MAXN], h[MAXN];
vector<Node> adj[MAXN];

void dfs(int u, int d) {
    depth[u] = d;
    for (Node x : adj[u]) {
        par[x.v][0] = u;
        h[x.v] = h[u] + x.w;
        dfs(x.v, d + 1);
    }
}

void build(void) {
    FOR(i, 1, LOG) FOR(u, 1, n) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
}

int LCA(int u, int v) {
    if (u == v) return u;

    if (depth[u] < depth[v]) swap(u, v);

    FORD(i, LOG, 0) if (depth[par[u][i]] >= depth[v]) u = par[u][i];

    if (u == v) return u;

    FORD(i, LOG, 0) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int dist(int u, int v) {
    int p = LCA(u, v);
    return h[u] + h[v] - 2 * h[p];
}

void process(void) {
    FOR(i, 1, n - 1) {
        int a, c;
        cin >> a >> c;
        a++;
        int b = i + 1;
        adj[a].push_back({b, c});
    }

    memset(par, 0, sizeof par);
    memset(h, 0, sizeof h);
    memset(depth, 0, sizeof depth);

    par[1][0] = 1;
    h[1] = 0;

    dfs(1, 1);
    build();


    int q; cin >> q; while (q--) {
        int x, y;
        cin >> x >> y;
        x++;
        y++;
        cout << dist(x, y) << " ";
    }
    cout << el;
    FOR(i, 1, n) {
        adj[i].clear();
        par[i][0] = 0;
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "B"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    while (cin >> n) {
        if (n == 0) break;
            process();
    }
    return 0;
}
