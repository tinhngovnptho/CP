#include<bits/stdc++.h>

// Author: Tinhnopro (a.k.a NVT)
// ngo viet tinh
using namespace std;

#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define ld long double
//#define int long long
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
const int LOG = log2(MAXN);

int n, par[MAXN], x[MAXN], v[MAXN];
vi adj[MAXN], virAdj[MAXN], nodes[MAXN];
vi divs[MAXN];
int num[MAXN], depth[MAXN], st[MAXN][LOG + 1], dp[MAXN], vist[MAXN];

void dfs(int u, int d) {
    static int timeDFS = 0;
    num[u] = ++timeDFS;
    depth[u] = d;
    for (int v : adj[u]) {
        dfs(v, d + 1);
    }
}

void preprocess(void) {
    FOR(i, 2, MAXN - 1) {
        for (int j = i; j < MAXN; j += i) divs[j].push_back(i);
    }
}

void buildLCA(void) {
    FOR(i, 1, n) st[i][0] = par[i];
    FOR(j, 1, LOG) for (int i = 1; i <= n; ++i) {
        st[i][j] = st[st[i][j - 1]][j - 1];
    }
}

int LCA(int u, int v) {
    if (u == v) return u;

    if (depth[u] < depth[v]) swap(u, v);

    FORD(i, LOG, 0) if (depth[st[u][i]] >= depth[v]) u = st[u][i];

    if (u == v) return u;

    FORD(i, LOG, 0) if (st[u][i] != st[v][i]) {
        u = st[u][i];
        v = st[v][i];
    }
    return st[u][0];
}

bool cmp(const int &u, const int &v) {
    return num[u] < num[v];
}

void buildVirtualTree(vi &node) {
    sort(ALL(node), cmp);
    int m = SZ(node);

    FOR(i, 0, m - 2) {
        int u = node[i];
        int v = node[i + 1];
        node.push_back(LCA(u, v));
    }

    sort(ALL(node), cmp);
    node.resize(unique(ALL(node)) - node.begin());
    m = SZ(node);

    FOR(i, 0, m - 1) {
        int u = node[i];
        virAdj[u].clear();
        dp[u] = -1;
    }

    FOR(i, 0, m - 2) {
        int u = LCA(node[i], node[i + 1]);
        int v = node[i + 1];
        virAdj[u].push_back(v);
    }
}

void calc(int u, const int &d) {
    dp[u] = 0;
    for (int &v : virAdj[u]) {
        if (dp[v] == -1) {
            calc(v, d);
        }
        dp[u] += dp[v];
    }
    if (dp[u] < v[u] && x[u] % d == 0) {
        dp[u] = v[u];
    }
}

void process(void) {
    cin >> n;
    par[1] = 1;
    FOR(i, 2, n) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    FOR(i, 1, n) cin >> x[i] >> v[i];

    buildLCA();
    dfs(1, 1);
    memset(vist, 0, sizeof vist);

    vi divisor;

    FOR(i, 1, n) {
        for (int &d : divs[x[i]]) {
            if (vist[d] == 0) {
                vist[d] = 1;
                nodes[d].clear();
                divisor.push_back(d);
            }
            nodes[d].push_back(i);
        }
    }

    ll res = -1, ru, rd;



    for (int &d : divisor) {
        buildVirtualTree(nodes[d]);

        for (int &u : nodes[d]) {
            if (dp[u] == -1) calc(u, d);
            if (maximize(res, 1LL * dp[u] * d)) {
                rd = d;
                ru = dp[u];
            }
        }
    }

    cout << res << el;
    FOR(i, 1, n) {
        adj[i].clear();
        virAdj[i].clear();
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "grandelection"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    preprocess();
    int t; cin >> t; while (t--)
    process();

    return 0;
}
