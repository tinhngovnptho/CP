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

#define name "TRANSFORM"

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
const int INF = 1e9 + 11; const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;
// const int BLOCK = 330;

struct Query {
    int type, u, v;

    void read(void) {
        cin >> type >> u >> v; 
    }
};

int n, q;
int a[MAXN];
Query queries[MAXN];

namespace Brute {
    void solve(void) {
        FOR(i, 1, q) {
            if (queries[i].type == 1) {
                a[queries[i].u] = queries[i].v;
            } else {
                int l = queries[i].u;
                int r = queries[i].v;
                int mx = -1, mi = INF;
                FOR(x, l, r) {
                    maximize(mx, a[x]);
                    minimize(mi, a[x]);
                }
                int res = INF; 
                FOR(x, l, r) FOR(y, x + 1, r) {
                    if (a[x] == mx && a[y] == mi || a[x] == mi && a[y] == mx) {
                        minimize(res, y - x); 
                    }
                }
                int cnt = 0;
                FOR(x, l, r) if (a[x] == mx && a[x + res] == mi || a[x] == mi && a[x + res] == mx) {
                    cnt++;
                }
                cout << res + 1 << " " << cnt << el;
            }
        }
    }
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".ans", "w", stdout);
    }
    //___________________________________
    cin >> n >> q;
    FOR(i, 1, n)  cin >> a[i];
    FOR(i, 1, q) queries[i].read();
    return Brute::solve(), 0;

    return 0;
}
