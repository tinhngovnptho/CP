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

#define int long long 

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 1e5 + 11;
const int INF = 1e9 + 11;

struct Node {
    int v, w;
    Node() {
        v = w = 0;
    }
    Node(int _v, int _w): v(_v), w(_w) {}
};

struct Data {
    int v, k, w;
    Data(int _v, int _k, int _w): v(_v), k(_k), w(_w) {}
    
    bool operator <(const Data& other) const {
        return w > other.w; 
    }
};


int n, m, k, c[MAXN];
vector<Node> adj[MAXN];
int f[MAXN], dist[MAXN][2];

void dijsktra(int s) {
    FOR(i, 1, n) f[i] = INF; 
    f[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().se;
        int d_u = pq.top().fi;
        pq.pop();
        if (d_u > f[u]) continue;
        for (const Node &x : adj[u]) {
            int v = x.v;
            int w = x.w;
            if (f[v] > f[u] + w) {
                f[v] = f[u] + w;
                pq.push({f[v], v});
            }
        }
    }
}

void solve(int s) {
    FOR(i, 1, n) {
        dist[i][0] = dist[i][1] = INF;        
    }
    dist[s][0] = 0;
    priority_queue<Data> pq;
    pq.push({s, 0, dist[s][0]});
    while (!pq.empty()) {
        int u = pq.top().v;
        int d_u = pq.top().w;
        int k = pq.top().k;
        pq.pop();
        if (d_u > dist[u][k]) continue;
        if (c[u] && k == 0) {
            if (minimize(dist[u][1], dist[u][k] - c[u])) {
                pq.push({u, 1, dist[u][1]});;
            }
        }
        for (const Node &x : adj[u]) {
            int v = x.v;
            int w = x.w;
            if (dist[v][k] > dist[u][k] + w) {
                dist[v][k] = dist[u][k] + w;
                pq.push({v, k, dist[v][k]});
            }
        }
    }
}

void process(void) {
    cin >> n >> m >> k;
    FOR(i, 1, m) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    FOR(i, 1, k) {
        int x, y;
        cin >> x >> y;
        maximize(c[x], y);
    }
    dijsktra(n);
    solve(n);
    FOR(i, 1, n - 1) {
        cout << (dist[i][1] <= f[i]) << el;
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "A"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
