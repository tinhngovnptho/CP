// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()
#define szv(v) ((int)(v).size())
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "quanho"

using ll = long long;
using ld = long double;
using ii = pair<int, ll>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, Y b) { 
    return a < b ? a = b, 1 : 0; 
}

template<class X, class Y> bool minimize(X &a, Y b) { 
    return a > b ? a = b, 1 : 0; 
}

template<class T> using vector2d = vector<vector<T>>;

const int MAXN = 5e5 + 11; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7;
// const int INF = 1e9 + 11; 
const ll INFF = 1e18 + 11; 

int n, m, p[MAXN];
vector<ii> adj[MAXN];
pair<ll, ll> d[MAXN];

void Dijsktra(int s) {
    FOR(i, 1, n) d[i] = {INFF, -INFF};
    d[s] = {0, p[s]};
    priority_queue<ii, vector<ii>, greater<ii>> pq; 
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().se;
        int d_u = pq.top().fi;
        pq.pop();
        if (d_u > d[u].fi) continue;
        for (ii &x : adj[u]) {
            int v = x.fi;
            int w = x.se; 
            if (d[v].fi > d[u].fi + w) {
                d[v].fi = d[u].fi + w;
                d[v].se = d[u].se + p[v];
                pq.push({d[v].fi, v});
            } else if (d[v].fi == d[u].fi + w) {
                maximize(d[v].se, d[u].se + p[v]);
            }
        }
    }
}

void solve(void) {
    cin >> n;
    FOR(i, 1, n) cin >> p[i];
    cin >> m;
    FOR(i, 1, m) {
        int u, v, c; 
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    Dijsktra(1);

    if (d[n].fi == INFF) cout << "impossible" << el;
    else cout << d[n].fi << " " << d[n].se << el;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    // int t; cin >> t; while (t--)
    solve();

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
