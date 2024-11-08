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

const int MAXN = 2009;

int n, q, a[MAXN], bit[MAXN], cnt[MAXN][MAXN];

void update(int u, int val) {
    for (; u < MAXN; u += u & -u) bit[u] += val;
}

int query(int u) {
    int res = 0;
    for (; u; u -= u & -u) res += bit[u];
    return res; 
}

void preprocess(void) {
    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            cnt[i][j] = query(min(a[i], a[j]) - 1); 
            update(a[j], 1);
        }
        FOR(j, i + 1, n) update(a[j], -1);
    }
}

void Compress(void) {
    vector<int> v;
    FOR(i, 1, n) v.push_back(a[i]);
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    FOR(i, 1, n) a[i] = lower_bound(ALL(v), a[i]) - v.begin() + 1;
}

void process(void) {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    Compress();
    preprocess();
    while (q--) {
        int l, r; 
        cin >> l >> r;
        ll ans = 0;
        FOR(j, l + 1, r - 1) ans += 1LL * cnt[l][j] * cnt[j][r];
        cout << ans << el; 
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "B"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
