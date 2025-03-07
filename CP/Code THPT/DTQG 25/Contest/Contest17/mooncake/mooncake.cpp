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

#define name "mooncake"

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

const int MAXN = 2e5 + 11, MAX = 1e6 + 11; 
// const int MOD = 1e9 + 7; 
const int INF = 1e9 + 11; const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;
// const int BLOCK = 330;

int n, a[MAXN];
ll sum[MAXN], t[MAX], d[MAX];

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);
    
    FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];
    int mi = *min_element(a + 1, a + n + 1);
    int mx = *max_element(a + 1, a + n + 1);
    FOR(y, mi, mx) {
        t[y] = sum[n] - 1ll * y * n;
        int k = lower_bound(a + 1, a + n + 1, y) - a - 1;
        d[y] = sum[k] - 1ll * y * k;
    } 

    int q; cin >> q; while (q--) {
        ll x, y; cin >> x >> y;
        ll res = INFF;
        FOR(i, 1, n) {
            (minimize(res, y * t[a[i]] - (x + y) * d[a[i]]));
        }
        // cout << k << " ";
        cout << res << el;
    }

    return 0;
}
