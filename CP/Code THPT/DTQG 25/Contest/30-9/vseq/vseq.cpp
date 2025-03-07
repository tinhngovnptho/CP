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
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define ONBIT(i, mask) (mask | MASK(i))
#define OFFBIT(i, mask) mask & ~(MASK(i))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 2e5 + 11;
int n, M, q, a[MAXN];
ll seg[4 * MAXN], lazy[4 * MAXN];

void down(int id) {
    if (!lazy[id]) return ;
    seg[id << 1] += lazy[id];
    seg[id << 1 | 1] += lazy[id];
    if (seg[id << 1] >= 0) seg[id << 1] %= M;
    if (seg[id << 1 | 1] >= 0) seg[id << 1 | 1] %= M;
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    if (seg[id << 1] == seg[id << 1 | 1]) seg[id] = seg[id << 1];
    else seg[id] = -1;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return ;
    if (l == r) {
        seg[id] += val;
        seg[id] %= M;
        lazy[id] += val;
        return ;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    if (seg[id << 1] == seg[id << 1 | 1]) seg[id] = seg[id << 1];
    else seg[id] = -1; 
}

ll query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -2;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    down(id);
    int left = query(id << 1, l, mid, u, v);
    int right = query(id << 1 | 1, mid + 1, r, u, v);
    if (left == right || left == -2 || right == -2) return max(left, right);
    else return -1;
}

void process(void) {
    cin >> n >> M >> q;
    FOR(i, 1, n) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int type, l, r, c; 
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> c;
            update(1, 1, n, l, r, c);
        } else {
            int val = query(1, 1, n, l, r);
            cout << (val == -1) << el;
        }
    }
} 

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "vseq"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}

