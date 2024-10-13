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

#define name "tree"

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
// const int INF = 1e9 + 11; const ll INFF = (ll) 1e18 + 11;
const int LOG = 22;
// const int BASE = 311;
// const int BLOCK = 330;

struct Query {
    char type;
    int x, c;

    void Read(void) {
        cin >> type;
        if (type == 'Q') cin >> c;
        else cin >> x >> c;
    }
};


int n, q, c[MAXN];
vi adj[MAXN], virAdj[MAXN];
Query queries[MAXN];
set<int> color[MAXN];

int timeIn[MAXN], timeOut[MAXN], up[LOG + 1][MAXN], depth[MAXN];

void dfs(int u, int parent) {
    static int timeDFS = 0;
    timeIn[u] = ++timeDFS;
    for (int &v : adj[u]) if (v != parent) {
        up[0][v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
    timeOut[u] = timeDFS;
}

bool is_ancestor(int u, int v) {
    return timeIn[u] <= timeIn[v] && timeOut[v] <= timeOut[u];
}

int LCA(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    FORD(i, LOG, 0) if (!is_ancestor(up[i][u], v)) {
        u = up[i][u];
    }

    return up[0][u];
}

void buildLCA(void) {
    up[0][1] = 1;
    FOR(i, 1, LOG) FOR(u, 1, n) {
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
}

bool cmp(const int &a, const int &b) {
    return timeIn[a] <= timeIn[b];
}

ll res = 0;

void buildVitrualTree(vi &nodes) {
    sort(all(nodes), cmp);
    int m = nodes.size();
    REP(i, 0, m - 1) {
        int u = nodes[i];
        int v = nodes[i + 1];
        nodes.push_back(LCA(u, v));
    } 

    sort(all(nodes), cmp);
    nodes.resize(unique(all(nodes)) - nodes.begin());

    m = nodes.size();
    REP(i, 0, m) {
        virAdj[i].clear();
    }

    REP(i, 0, m - 1) {
        int u = LCA(nodes[i], nodes[i + 1]);
        int v = nodes[i + 1];
        virAdj[u].push_back(v);
        res += depth[v] - depth[u];
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
    cin >> n;
    FOR(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, n) {
        cin >> c[i];
        color[c[i]].insert(i);
    }
    cin >> q;
    FOR(i, 1, q) queries[i].Read();

    depth[1] = 1;
    dfs(1, 1);
    buildLCA();

    FOR(i, 1, q) {
        if (queries[i].type == 'U') {
            int x = queries[i].x;
            int _c = queries[i].c;
            color[c[x]].erase(color[c[x]].find(x));
            color[_c].insert(x);
            c[x] = _c; 
        } else {
            int _c = queries[i].c;
            vi nodes(color[_c].begin(), color[_c].end());
            if (nodes.size() == 0) {
                cout << -1 << el;
                continue;
            }
            buildVitrualTree(nodes);
            cout << res << el;
            res = 0;
        }
    }

    return 0;
}
