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
const int LOG = 20;

struct Node {
    int v, w;
    Node(int _v, int _w) : v(_v), w(_w) {}
};

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int n, q;
vector<Node> adj[MAXN];
vector<Edge> edges;
int timeIn[MAXN << 1], timeOut[MAXN << 1], st[MAXN][LOG + 1], depth[MAXN];
ll bit[MAXN << 1];

void update(int u, int val) {
    for (; u <= 2 * n; u += u & -u) bit[u] += val;
}

ll getRange(int u) {
    ll res = 0;
    for (; u; u -= u & -u) res += bit[u];
    return res; 
}

void dfs(int u, int parent) {
    static int timeDfs = 0;
    timeIn[u] = ++timeDfs;
    for (const Node &x : adj[u]) {
        int v = x.v;
        int w = x.w;
        if (v == parent) continue;
        
        st[v][0] = u;
        depth[v] = depth[u] + 1; 

        dfs(v, u);

        update(timeIn[v], w);
        update(timeOut[v], -w);
    }
    timeOut[u] = ++timeDfs;
}

void buildLCA(void) {
    st[1][0] = 1;
    FOR(i, 1, LOG) FOR(u, 1, n) {
        st[u][i] = st[st[u][i - 1]][i - 1];
    }
}

bool is_act(int u, int v) {
    return timeIn[u] <= timeIn[v] && timeOut[v] <= timeOut[u];
}

int LCA(int u, int v) {
    if (is_act(u, v)) return u;
    if (is_act(v, u)) return v;
    
    FORD(i, LOG, 0) if (!is_act(st[u][i], v)) {
        u = st[u][i];
    }
    return st[u][0];
} 

void process(void) {
    cin >> n;
    FOR(i, 1, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        edges.push_back({a, b, w});
    }
    dfs(1, 1);
    buildLCA();
    int q; cin >> q;
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            int &u = edges[a - 1].u;
            int &v = edges[a - 1].v;
            int &w = edges[a - 1].w;

            if (u != st[v][0]) swap(u, v);

            update(timeIn[v], b - w);
            update(timeOut[v], w - b);
            w = b;
        } else {
            int lca = LCA(a, b);
            cout << getRange(timeIn[a]) + getRange(timeIn[b]) - 1LL * 2 * getRange(timeIn[lca]) << el; 
        }
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "euler_c"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
