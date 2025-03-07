/*
    Author: Tinhnopro (Tinh nop)
    From: CHV Phu Tho
 */
#include <bits/stdc++.h>

using namespace std;

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
    static_assert(D >= 1);
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};

template <typename T>
struct vec<T, 1> : public vector<T> {
    vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};

template <typename T>
using tpair = pair<T, T>;

template <typename T>
int Size(const T &a) { return a.size(); }

template <typename T1, typename T2>
bool maximize(T1 &a, T2 b) {
    return a < b ? a = b, true : false;
}

template <typename T1, typename T2>
bool minimize(T1 &a, T2 b) {
    return a > b ? a = b, true : false;
}
// End of tempalte
const int MAXN = 2e5 + 11;
const int INF = 1e9 + 11;
const int LOG = 20;

int n, q;
vector <int> adj[MAXN];
int depth[MAXN], tpar[LOG + 1][MAXN], par_ct[MAXN], sz[MAXN], deleted[MAXN];
int ans[MAXN];

void dfs(int u, int parent = -1) {
    tpar[0][u] = parent;
    for (int i = 1; i <= LOG; ++i) tpar[i][u] = tpar[i - 1][tpar[i - 1][u]];
    for (auto &v : adj[u]) if (v != parent) {
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int countChild(int u, int parent = -1) {
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != parent && !deleted[v]) {
        sz[u] += countChild(v, u);
    }
    return sz[u];
}

int findCentroid(const int &targs, int u, int parent = -1) {
    for (auto &v : adj[u]) if (v != parent && !deleted[v] && sz[v] > targs) {
        return findCentroid(targs, v, u);
    }
    return u;
}

void centroid_decomp(int u, int parent = -1) {
    int cnt = countChild(u) >> 1;
    int centroid = findCentroid(cnt, u);
    par_ct[centroid] = parent;
    deleted[centroid] = true;
    ans[centroid] = INF;
    for (auto &v : adj[centroid]) if (!deleted[v]) {
        centroid_decomp(v, centroid);
    }
}

int lca(int u, int v) {
    if (u == v) return u;
    if (depth[u] < depth[v]) swap(u, v);
    int dist = depth[u] - depth[v];
    for (int i = 0; i <= LOG; ++i) if (dist & (1 << i)) {
        u = tpar[i][u];
    }
    if (u == v) return u;
    for (int i = LOG; ~i; --i) if (tpar[i][u] != tpar[i][v]) {
        u = tpar[i][u]; v = tpar[i][v];
    }
    return tpar[0][u];
}

int dist(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}

void upd_cen_tree(int u) {
    int i = u;
    while (i) {
        int d = dist(i, u);
        minimize(ans[i], d);
        i = par_ct[i];
    }
}

int get_cen_tree(int u) {
    int res = INF, i = u;
    while (i) {
        int d = dist(i, u);
        minimize(res, ans[i] + d);
        i = par_ct[i];
    }
    return res;
}


void Tinhnopro(void) {
    cin >> n >> q;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, 1);
    centroid_decomp(1, 0);
    upd_cen_tree(1);

    while (q--) {
        int type, i;
        cin >> type >> i;
        // assert(type <= 2);
        if (type == 1) {
            upd_cen_tree(i);
        } else {
            cout << get_cen_tree(i) << '\n';
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define name "centroid_c"
    if (fopen(name".inp", "r"))
        freopen(name".inp", "r", stdin),
        freopen(name".out", "w", stdout);

    // int t; cin >> t; while (t--)
    Tinhnopro();

    cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s \n";
    return 0;
}

