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

const int MAXN = (int) 2e5 + 11; 

int n, q;
ll a[MAXN];
vi adj[MAXN];
int timeIn[MAXN], timeOut[MAXN];
ll sum[MAXN];
ll seg[4 * MAXN], lazy[4 * MAXN];

void dfs(int u, int parent) {
    static int timeDFS = 0;
    timeIn[u] = ++timeDFS;
    for (int &v : adj[u]) if (v != parent) {
        sum[v] = sum[u] + a[v]; 
        dfs(v, u);
    }
    timeOut[u] = timeDFS;
}

void down(const int& id, const int& l, const int& r, const int& mid) {
    if (!lazy[id]) return ;
    if (l != r){
    seg[id << 1] += 1LL * lazy[id] * (mid - l + 1);
    seg[id << 1 | 1] += 1LL * lazy[id] * (r - mid);
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return ;
    if (u <= l && r <= v) {
        seg[id] += 1LL * (r - l + 1) * val;
        lazy[id] += val;
        return ;
    }
    int mid = l + r >> 1;
    down(id, l, r, mid);
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

ll query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = l + r >> 1;
    down(id, l, r, mid);
    return query(id << 1, l, mid, u, v) + query(id << 1 | 1, mid + 1, r, u, v);
}

void process(void) {    
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sum[1] = a[1];
    dfs(1, 1);
    while (q--) {
        int type, s, x;
        cin >> type;
        if (type == 1) {
            cin >> s >> x;
            update(1, 1, n, timeIn[s], timeOut[s], x - a[s]);
            a[s] = x;
        } else {
            cin >> s;
            cout << sum[s] + query(1, 1, n, timeIn[s], timeIn[s]) << el;
        }
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "euler_b"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
