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
int v[MAXN], n, q;
vector<int> adj[MAXN];
int timein[MAXN], timeout[MAXN];
ll bit[MAXN];

void update(int u, int val) {
    for (; u <= n; u += u & -u) bit[u] += val;
}

ll query(int u) {
    ll res = 0;
    for (; u; u -= u & -u) res += bit[u];
    return res; 
}

ll getrange(int l, int r) {
    return query(r) - query(l - 1);
}

void dfs(int u, int parent) {
    static int timeDFS = 0;
    timein[u] = ++timeDFS;
    update(timein[u], v[u]);

    for (int &v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }

    timeout[u] = timeDFS; 
}



void process(void) {
    cin >> n >> q;
    FOR(i, 1, n) cin >> v[i];
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    while (q--) {
        int type, u, x;
        cin >> type >> u;
        if (type == 1) {
            cin >> x;
            update(timein[u], -v[u] + x);
            v[u] = x;
        } else {
            cout << getrange(timein[u], timeout[u]) << el;
        }
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "euler_a"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
