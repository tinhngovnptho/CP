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

#define name "MATROSKA"

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
const int INF = 1e9 + 11; 

int n, a[MAXN];

struct Segtree {
    int st[4 * MAXN], lazy[4 * MAXN];

    Segtree() {
        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);
    }

    void down(int id) {
        if (!lazy[id]) return ;
        st[id << 1] += lazy[id];
        st[id << 1 | 1] += lazy[id];
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        lazy[id] = 0; 
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u) return ;
        if (u <= l && r <= v) {
            st[id] += val;
            lazy[id] += val;
            return ;
        }
        down(id);
        int mid = (l + r) >> 1;
        
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);

        st[id] = min(st[id << 1], st[id << 1 | 1]);
    }

    int query(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return INF;
        if (u <= l && r <= v) return st[id];
        down(id);
        int mid = (l + r) >> 1;
        return min(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v)); 
    }
} it;

int m;

void compress(void) {
    vi res; 
    FOR(i, 1, n) res.push_back(a[i]);
    sort(all(res));
    res.resize(unique(all(res)) - res.begin());
    FOR(i, 1, n) a[i] = lower_bound(all(res), a[i]) - res.begin() + 1;
    m = res.size();
}

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
    compress();

    int ans = 0;

    it.update(1, 0, m, a[1], m, 1);
    it.update(1, 0, m, a[2] - 1, m, -1);

    if (it.query(1, 0, m, 0, m) == 0) ans = 1;

    FOR(k, 2, n / 2) {
        it.update(1, 0, m, a[k] - 1, m, 1);
        it.update(1, 0, m, a[k], m, 1);
        it.update(1, 0, m, a[2 * k] - 1, m, -1);
        it.update(1, 0, m, a[2 * k - 1] - 1, m, -1);
        if (it.query(1, 0, m, 0, m) == 0) ans = k;
    }

    cout << ans;

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
