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

#define name "segtree_itladder"

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
const int MOD = 1e9 + 7; 
// const int INF = 1e9 + 11; const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;
// const int BLOCK = 330;

int n, q;

struct Node {
    ll lz_a, lz_b, val; 

    Node() {
        lz_a = lz_b = val = 0;
    }
};

Node seg[4 * MAXN];

int sum(int a, int b) {
    ll x = (b - a + 1) * (b - a) / 2; 
    x %= MOD;
    return x;
}

void down(const int &id,const int &l,const int &r,const int &mid) {
    if (!seg[id].lz_a && !seg[id].lz_b) return ;
    seg[id << 1].val += 1ll * seg[id].lz_a * sum(l, mid);
    seg[id << 1].val %= MOD;
    seg[id << 1].val += 1ll * seg[id].lz_b * (mid - l + 1);
    seg[id << 1].val %= MOD;
    seg[id << 1 | 1].val += 1ll * seg[id].lz_a * sum(mid + 1, r);
    seg[id << 1 | 1].val %= MOD;
    seg[id << 1 | 1].val += 1ll * seg[id].lz_b * (r - mid);
    seg[id << 1 | 1].val %= MOD;
    seg[id << 1].lz_a += seg[id].lz_a;
    seg[id << 1].lz_b += seg[id].lz_b;
    seg[id << 1 | 1].lz_a += seg[id].lz_a;
    seg[id << 1 | 1].lz_b += seg[id].lz_b;
    seg[id].lz_a = seg[id].lz_b = 0;    
}

void update(int id, int l, int r, int u, int v, int a, int b) {
    if (l > v || r < u) return ;
    if (u <= l && r <= v) {
        seg[id].val += 1ll * a * sum(l, r);
        seg[id].val %= MOD;
        seg[id].val += 1ll * b * (r - l + 1);
        seg[id].val %= MOD;
        seg[id].lz_a += a;
        seg[id].lz_b += b;
        return ;
    }

    int mid = (l + r) >> 1;
    down(id, l, r, mid);

    update(id << 1, l, mid, u, v, a, b);
    update(id << 1 | 1, mid + 1, r, u, v, a, b);
    
    seg[id].val = seg[id << 1].val + seg[id << 1 | 1].val;
    seg[id].val %= MOD;
}

int getsum(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return seg[id].val;
    int mid = (l + r) >> 1;
    down(id, l, r, mid);
    return (getsum(id << 1, l, mid, u, v) + getsum(id << 1 | 1, mid + 1, r, u, v)) % MOD;
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

    while (q--) {
        int type, l, r, a, b;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> a >> b;
            update(1, 1, n, l, r, a, b);
        } else {
            cout << getsum(1, 1, n, l, r) << el;
        }
    }

    return 0;
}
