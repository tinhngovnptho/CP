// Author: tinhnopro (tinh nop)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 11;
const int64_t INF = (int64_t) 1e18 + 11;

int n, q;
int64_t c[MAXN];
vector<int> adj[MAXN];
int timein[MAXN], timeout[MAXN];
int64_t st[MAXN], lazy[MAXN];

void dfs(int u, int parent = -1) {
    static int timeDFS = 0;
    timein[u] = ++timeDFS;
    for (int v : adj[u]) if (v != parent) {
        dfs(v, u);
    }
    timeout[u] = timeDFS;
}

void down(int id) {
    if (!lazy[id]) return ;
    st[id << 1] += lazy[id];
    st[id << 1 | 1] += lazy[id];
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return ;
    if (u <= l && r <= v) {
        st[id] += val;
        lazy[id] += val;
        return ;
    }
    int mid = (l + r) >> 1;
    down(id);
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int64_t Getmax(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -INF;
    if (u <= l && r <= v) {
        return st[id];
    }
    down(id);
    int mid = (l + r) >> 1;
    return max(Getmax(id << 1, l, mid, u, v),
               Getmax(id << 1 | 1, mid + 1, r, u, v));
}

void run_case(void) {
    cin >> n >> q;
    cin >> c[1];
    for (int i = 2, par; i <= n; ++i) {
        cin >> c[i] >> par;
        adj[par].push_back(i);
        adj[i].push_back(par);
    }
    dfs(1);

    while (q--) {
        char type; cin >> type;
        if (type == 'p') {
            int A, x; cin >> A >> x;
            update(1, 1, n, timein[A] + 1, timeout[A], x);
        } else {
            int A; cin >> A;
            cout << c[A] + Getmax(1, 1, n, timein[A], timein[A]) << '\n';
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("salary.inp", "r")) {
        freopen("salary.inp", "r", stdin);
        freopen("salary.out", "w", stdout);
    }

    int tests = 1;
    // cin >> tests;
    while (tests--) run_case();
    cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s tinhnop";
}
