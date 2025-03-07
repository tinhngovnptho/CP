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
#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((i) & MASK(x))
#define ONBIT(x, i) ((i) | MASK(x))
#define OFFBIT(x, i) ((i) & ~MASK(x))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = (int) 2e5 + 11;
const int LOG = 20;

int n, q, p[MAXN], st[LOG + 1][MAXN];

void build(void) {
    FOR(i, 1, n + 1) st[0][i] = p[i];
    FOR(j, 1, LOG) {
        for (int i = 1; i + MASK(j) - 1 <= n + 1; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + MASK(j - 1)]);
    }
}

int lifting(int pos, int val) {
    FORD(j, log2(n + 1 - pos), 0) {
        if (pos + MASK(j) <= n + 1 && st[j][pos] > val) pos += MASK(j);
    }
    return pos;
}

void process(void) {
    cin >> n >> q;
    FOR(i, 1, n) cin >> p[i];
    p[n + 1] = -1;
    build();
    while (q--) {
        int l, r, t;
        cin >> t >> l >> r;
        while (l <= r) {
            l = lifting(l, t);
            if (l > r) break;
            t %= p[l];
        }
        cout << t << el;
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "C"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

//    int t; cin >> t; while (t--)
    process();

    return 0;
}
