// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define all(v) (v).begin(), (v).end()
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "c"

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, Y b) { 
    return a < b ? a = b, 1 : 0; 
}
template<class X, class Y> bool minimize(X &a, Y b) { 
    return a > b ? a = b, 1 : 0; 
}

const int MAXN = 1e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int n, w[MAXN], a[MAXN], b[MAXN];

struct DSU {
    int lab[MAXN], sum[MAXN], mi[MAXN];

    void reset(void) {
        memset(lab, -1, sizeof lab);
        memset(mi, 0, sizeof mi);
        memset(sum, 0, sizeof sum);
    }

    int sz(int u) {
        return -lab[u];
    }

    int find_par(int u) {
        return lab[u] < 0 ? u : lab[u] = find_par(lab[u]);
    }

    void union_set(int u, int v) {
        u = find_par(u);
        v = find_par(v);

        if (u == v) return;

        if (lab[u] > lab[v]) swap(u, v);

        sum[u] += sum[v];
        minimize(mi[u], mi[v]);
        lab[u] += lab[v];
        lab[v] = u;
    }
} dsu;

bool processed[MAXN];

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    //___________________________________
    cin >> n;
    FOR(i, 1, n) cin >> w[i];
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    dsu.reset();

    FOR(i, 1, n) dsu.sum[i] = dsu.mi[i] = w[i];

    FOR(i, 1, n) dsu.union_set(a[i], b[i]);

    ll ans = 0;

    FOR(i, 1, n) {
        int u = dsu.find_par(i);
        if (processed[u]) continue;

        ans += dsu.sum[u] + 1ll * dsu.mi[u] * (dsu.sz(u) - 2);
        processed[u] = true;
    }

    cout << ans;

    // cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
