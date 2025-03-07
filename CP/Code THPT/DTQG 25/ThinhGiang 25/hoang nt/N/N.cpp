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

#define name "N"

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
// const ll INFF = 1e18 + 11; 

int n;
vi a;
vi pos[MAXN];

struct Compress {
    vi zip;
    
    void add(int x) {
        zip.push_back(x);
    }

    void reset(void) {
        zip.clear();
    }

    void init(void) {
        sort(all(zip));
        zip.resize(distance(zip.begin(), unique(all(zip))));
    }

    int get(int x) {
        return lower_bound(all(zip), x) - zip.begin() + 1;
    }
} z;

int bit[MAXN];

#define lowbit(x) ((x) & -(x))

void solve(void) {
    cin >> n;
    a.resize(n + 1, 0);
    FOR(i, 1, n) {
        cin >> a[i];
    }

    FOR(i, 1, n) {
        z.add(a[i]);
    }

    z.init();

    int sz = z.zip.size();
    
    vi cnt(sz + 1, 0), l(sz + 1, -1), r(sz + 1, 0);

    FOR(i, 1, n) {
        a[i] = z.get(a[i]);
        cnt[a[i]]++;
        if (l[a[i]] < 0) l[a[i]] = i;
        r[a[i]] = i;
    }

    FOR(i,)

    z.reset();
    for (int x : a) pos[x].clear();
    a.clear();
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    int t; cin >> t; while (t--) {
        solve();
    }

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
