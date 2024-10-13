#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define ll  long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi  vector<int>
#define fi  first
#define se  second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORX(i, a, b, x) for (int i = (a), _b = (b); i <= _b; i += (x))
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = (int) 5e2 + 11;
//const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, m, Ha, Sa, Hb, Sb;
vector<pii> adj[MAXN];
int D_sa[MAXN], D_sb[MAXN], D_ha[MAXN], D_hb[MAXN];
int back_ha[MAXN], back_hb[MAXN], back_sa[MAXN], back_sb[MAXN];

void Dijsktra(int s, int *d, int *Back) {
    FOR(i, 1, n) d[i] = INF;
    d[s] = 0;

    static priority_queue<pii, vector<pii>, greater<pii> > pq;
    while (!pq.empty()) pq.pop();
    pq.push({0, s});
    Back[s] = -1;

    while (!pq.empty()) {
        int u = pq.top().se;
        int d_u = pq.top().fi;
        pq.pop();
        if (d_u > d[u]) continue;
        for (pii x : adj[u]) {
            int v = x.fi;
            int w = x.se;
            if (minimize(d[v], d[u] + w)) {
                Back[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

bool checkA(int vertex) {
    return (D_ha[vertex] + D_sa[vertex] == D_sa[Ha]);
}

bool checkB(int vertex) {
    return (D_hb[vertex] + D_sb[vertex] == D_sb[Hb]);
}

void trace(int pos, int *backh, int *backs) {
    vector<int> v;
    int t = pos;
    v.push_back(t);
    while (backh[t] != -1) {
        t = backh[t];
        v.push_back(t);
    }
    t = pos;
    reverse(ALL(v));
    while (backs[t] != -1) {
        t = backs[t];
        v.push_back(t);
    }
    for (int x : v) cout << x << " ";
    cout << el;
}

void process(void) {
    cin >> n >> m >> Ha >> Sa >> Hb >> Sb;
    FOR(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijsktra(Sa, D_sa, back_sa);
    Dijsktra(Sb, D_sb, back_sb);
    Dijsktra(Ha, D_ha, back_ha);
    Dijsktra(Hb, D_hb, back_hb);



    int min_time = INF, pos = -1;

    FOR(i, 1, n) {
        if (checkA(i) && checkB(i) && D_ha[i] == D_hb[i]) {
            if (minimize(min_time, D_ha[i])) {
                pos = i;
            }
        }
    }

    if (pos == -1) return void(cout << "NO\n");

    cout << "YES\n";
    cout << D_sa[Ha] << el;
    trace(pos, back_ha, back_sa);
    cout << D_sb[Hb] << el;
    trace(pos, back_hb, back_sb);
    cout << pos << el << min_time;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("B");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
