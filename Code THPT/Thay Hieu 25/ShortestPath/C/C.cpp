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
const int INF = 1e9 + 11;

struct Node {
    int v, c, d;

    Node(int _v, int _c, int _d) {
        v = _v;
        c = _c;
        d = _d;
    }
};

int n, m, s, t, W;
vector<Node> adj[MAXN];
int d[MAXN];
set<int> S;

#define mp make_pair

void dijsktra(int s, int cmin) {
    FOR(i, 1, n) d[i] = INF;
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mp(0, s));
    while (!pq.empty()) {
        int u = pq.top().se;
        int d_u = pq.top().fi;
        pq.pop();
        if (d_u > d[u]) continue;
        FORA(it, adj[u]) {
            int v = it->v;
            int w = it->d;
            int c = it->c;
            if (c < cmin) continue;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(mp(d[v], v));
            }
        }
    }
}

void process(void) {
    cin >> n >> m >> s >> t >> W;

    FOR(i, 1, m) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        adj[u].push_back(Node(v, c, d));
        adj[v].push_back(Node(u, c, d));
        S.insert(c);
    }

    ld ans = INF;

    FORA(it, S) {
        dijsktra(s, *it);
        ans = min(ans, (ld) d[t] + (ld) W / *it);
    }

    cout << fixed << setprecision(2) << ans;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "C"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

//    int t; cin >> t; while (t--)
    process();

    return 0;
}
