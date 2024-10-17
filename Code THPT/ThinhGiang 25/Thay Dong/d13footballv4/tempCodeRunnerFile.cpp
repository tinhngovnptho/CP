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

#define name "d13footballv4"

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

const int MAXN = 1e3 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int n, q, k;
vi adj[MAXN];
ii queries[MAXN];
int c[MAXN][MAXN];

bool cmp(const int &a, const int &b) {
    return c[a][b] > c[b][a];
}

void solve1(void) {
    FOR(i, 1, q) {
        int L = queries[i].first;
        int R = queries[i].second;
        vi res;
        FOR(j, L, R) res.push_back(j);
        sort(all(res), cmp);
        cout << R - L + 1 << " ";
        for (int x : res) cout << x << " ";
        cout << el;
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
    cin >> n >> q >> k;
    FOR(i, 1, q) cin >> queries[i].fi >> queries[i].se;    
    FOR(i, 1, n) FOR(j, 1, n) {
        int x; cin >> x;
        c[i][j] = x;
        if (x == 1) {
            adj[i].push_back(j);
        }
    }

    if (k == 1) return solve1(), 0;
    else cout << 1 / 0;

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
