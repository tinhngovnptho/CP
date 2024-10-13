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


#define name "d13vseqt4"

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

const int MAXN = 2e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int n, M, q, a[MAXN], lazy[4 * MAXN];

struct Node {
    bool flag; 
    int val;
    Node(int x, bool d) : val(x), flag(d) {}
    Node() { val = -1; flag = 0; }

    friend Node operator +(const Node &a, const Node &b) {
        if (a.val == -2) return b;
        if (b.val == -2) return a;
        Node res; 
        res.flag = 0;
        if (a.flag && b.flag && a.val == b.val) res.flag = 1;
        res.val = min(a.val, b.val);
        if (res.flag == 0) res.val = -1;
        return res; 
    } 
};

Node seg[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        seg[id].val = a[l];
        seg[id].flag = 1;
        return ;
    }

    int mid = (l + r) >> 1;

    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

void down(int id) {
    if (!lazy[id]) return ;
    
    if (seg[id << 1].val != -1) {
        seg[id << 1].val += lazy[id];
        seg[id << 1].val %= M;
    }

    if (seg[id << 1 | 1].val != -1) {
        seg[id << 1 | 1].val += lazy[id];
        seg[id << 1 | 1].val %= M;
    }

    (lazy[id << 1] += lazy[id]) %= M;
    (lazy[id << 1 | 1] += lazy[id]) %= M;
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return ;
    if (u <= l && r <= v) {
        if (seg[id].val != -1) {
            seg[id].val += val;
            seg[id].val %= M;
        }
        (lazy[id] += val) %= M;
        
        return ;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

Node asked(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return {-2, 0};
    if (u <= l && r <= v) return seg[id];
    down(id);
    int mid = (l + r) >> 1;
    return asked(id << 1, l, mid, u, v) + asked(id << 1 | 1, mid + 1, r, u, v);
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> M >> q;
    FOR(i, 1, n) cin >> a[i];
    build(1, 1, n);

    while (q--) {   
        int op, l, r, c;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> c;
            update(1, 1, n, l, r, c);
        } else {
            cout << !asked(1, 1, n, l, r).flag << el;
        }
    }

    return 0;
}
