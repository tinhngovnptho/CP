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

struct Node {
    int u, v, c;
    bool isSE;
    Node() {
        u = v = c = isSE = 0;
    }
    Node(int _u, int _v, int _c) {
        u = _u;
        v = _v;
        c = _c;
        isSE = 0;
    }
    bool operator < (const Node &other) const {
        return c < other.c;
    }
};

struct DSU {
    int lab[MAXN];

    DSU() {
        memset(lab, -1, sizeof lab);
    }

    void clear(int sz) {
        FOR(i, 1, sz) lab[i] = -1;
    }

    int find_par(int u) {
        return lab[u] < 0 ? u : lab[u] = find_par(lab[u]);
    }

    bool union_set(int u, int v) {
        u = find_par(u);
        v = find_par(v);

        if (u == v) return false;

        if (u > v) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;

        return true;
    }
} dsu;

int n, m, isDel[MAXN];
vector<Node> edges;

int find_mst(void) {
    dsu.clear(n);
    int c = 0;
    FOR(i, 0, m - 1) if (!isDel[i]) {
        if (!dsu.union_set(edges[i].u, edges[i].v)) continue;
        c += edges[i].c;
    }
    return c;
}

void process(void) {
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Node(u, v, c));
    }
    int cmin = 0;
    sort(ALL(edges));

    FORA(it, edges) {
        if (!dsu.union_set(it->u, it->v)) continue;
        cmin += it->c;
        it->isSE = true;
    }

    cout << cmin << " ";
    int cmin2 = 1e9 + 11;
    FOR(i, 0, m - 1) if (edges[i].isSE) {
        isDel[i] = 1;
        int mst = find_mst();
        if (mst >= cmin) minimize(cmin2, mst);
        isDel[i] = 0;
    }
    cout << cmin2;
}


signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "B"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

//    int t; cin >> t; while (t--)
    process();

    return 0;
}
