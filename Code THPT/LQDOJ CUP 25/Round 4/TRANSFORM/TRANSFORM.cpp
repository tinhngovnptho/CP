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

#define mask(x) (1 << (x))
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
const int LOG = 22;
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

namespace Sub2 {
    bool check(void) {
        FOR(i, 1, n - 1) if (a[i] > a[i + 1]) return false; 
        FOR(i, 1, q) if (queries[i].type == 1) return false;
        return true; 
    }

    void solve(void) {
        FOR(i, 1, q) {
            int l = queries[i].u;
            int r = queries[i].v;
            int idx_l = upper_bound(a + l, a + r + 1, a[l]) - a - 1; 
            int idx_r = lower_bound(a + l, a + r + 1, a[r]) - a;
            cout << idx_r - idx_l  + 1 << " " << 1 << el;
        }
    }
}

namespace Sub3 {
    bool check(void) {
        FOR(i, 1, n) if (a[i] > n) return false; 
        FOR(i, 1, q) if (queries[i].type == 1) return false;
        return true; 
    }

    int mx[LOG + 1][MAXN], mi[LOG + 1][MAXN], lg[MAXN], pos[MAXN];

    void build(void) {
        FOR(i, 1, n) mx[0][i] = mi[0][i] = a[i];
        FOR(i, 1, LOG) for (int j = 1; j + mask(i) - 1 <= n; ++j) {
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + mask(i - 1)]);
            mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + mask(i - 1)]);
        }
        FOR(i, 1, n) lg[i] = lg[i / 2] + 1; 
    }

    int getmax(int l, int r) {
        int k = lg[r - l + 1];
        return max(mx[k][l], mx[k][r - mask(k) + 1]); 
    }

    int getmin(int l, int r) {
        int k = lg[r - l + 1];
        return min(mi[k][l], mi[k][r - mask(k) + 1]);
    }

    void solve(void) {
        build();
        FOR(i, 1, n) pos[a[i]] = i;
        FOR(i, 1, q) {
            int l = queries[i].u;
            int r = queries[i].v;
            int mi = getmin(l, r);
            int mx = getmax(l, r);
            int idx_mi = pos[mi];
            int idx_mx = pos[mx];
            if (idx_mi > idx_mx) swap(idx_mi, idx_mx);
            cout << idx_mx - idx_mi + 1 << " " << 1 << el;
        }
    }
}

namespace Sub4 {
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
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> q;
    FOR(i, 1, n)  cin >> a[i];
    FOR(i, 1, q) queries[i].read();
    if (n <= 800 && q <= 800) return Brute::solve(), 0;
    if (Sub2::check()) return Sub2::solve(), 0;
    if (Sub3::check()) return Sub3::solve(), 0;
    if (q <= 400) return Sub4::solve(), 0;

    return 0;
}
