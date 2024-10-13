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

#define name "d13farmv4"
#define int long long 

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
// const int INF = 1e9 + 11; const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;
// const int BLOCK = 330;

struct Query {
    int d, idx; 
    
    void read(void) {
        cin >> d;
    }
};

int n, q, a[MAXN];
Query queries[MAXN];
ll sum = 0;


struct DSU {
    int lab[MAXN], total[2][MAXN], mx[MAXN];
    long long ans = 0;
    void init(void) {
        memset(lab, -1, sizeof lab);
        FOR(i, 1, n) {
            total[i % 2][i] = a[i];
            mx[i] = i;
        }
    }

    int find_par(int x) {
        return lab[x] < 0 ? x : lab[x] = find_par(lab[x]);
    }

    void merge(int u, int v) {
        u = find_par(u);
        v = find_par(v);

        if (u == v) return ;
        
        if (lab[u] > lab[v]) swap(u, v);

        ans -= total[mx[u] & 1 ^ 1][u];
        ans -= total[mx[v] & 1 ^ 1][v];


        lab[u] += lab[v];
        lab[v] = u;

        total[0][u] += total[0][v];
        total[1][u] += total[1][v];
        mx[u] = max(mx[u], mx[v]);

        
        ans += total[mx[u] & 1 ^ 1][u];
    }
} dsu;

namespace Brute {
    void solve(void) {
        FOR(test, 1, q) {
            int d = queries[test].d;
            int j = n;
            ll res = 0;
            FORD(i, n - 1, 1) {
                if (i == 0) break;
                if (a[j] - a[i] <= d) {
                    res += a[i];
                    j = i - 1;
                    i--;
                } else j--;
            }
            cout << sum - res << el;
        }
    }
}

namespace Subfull {

    bool cmp(const Query &a, const Query &b) {
        return a.d < b.d;
    }

    ll res[MAXN];
    Query diff[MAXN];

    void solve(void) {
        dsu.init();
        sort(queries + 1, queries + q + 1, cmp);
        FOR(i, 2, n) {
            diff[i].d = a[i] - a[i - 1];
            diff[i].idx = i;
        }
        sort(diff + 2, diff + n + 1, cmp);
        int l = 2;
        FOR(i, 1, q) {
            while (l <= n && diff[l].d <= queries[i].d) {
                dsu.merge(diff[l].idx, diff[l].idx - 1);
                l++;
            }
            res[queries[i].idx] = sum - dsu.ans;
        }
        FOR(i, 1, q) cout << res[i] << el;
    }
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> q;

    FOR(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);

    FOR(i, 1, q) {
        queries[i].read();
        queries[i].idx = i;
    }

    Subfull::solve();

    return 0;   
}
