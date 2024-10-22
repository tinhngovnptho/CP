/**------------------------------------------
------Author: Tinhnopro (Tinh nop) ----------
---------From: CHV with luv <3 --------------
---------Value = Live + Love ---------------- 
------------------------------------------**/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second
#define eb emplace_back

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()

#define Mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | Mask(i))
#define offbit(i, mask) (mask & ~(Mask(i)))
#define cntbit(x) __builtin_popcountll(x)
#define Log2(x) (63 - __builtin_clzll(x))

using namespace std;

using int64 = long long;
using db = long double;
using vi = vector<int>;
using ii = pair<int, int>;
using ii64 = pair<int64, int64>;

template<class X, class Y> bool maximize(X &a, Y b) { 
    return a < b ? a = b, 1 : 0; 
}

template<class X, class Y> bool minimize(X &a, Y b) { 
    return a > b ? a = b, 1 : 0; 
}

template<class X, class Y> void modmize(X &a, const Y &b) { 
    if (a >= b) a -= b; 
}

template<class T> using vector2d = vector<vector<T>>;

// const int dx[8] = {+1, -1, +0, +0, +1, -1, +1, -1}, dy[8] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int INF = 1e9 + 11, LOG = 25, BLOCK = 700, MAXN = 5e5 + 11, MAX = 1e6 + 11;
// const ll INFF = 1e18 + 7, BASE = 311, MOD = 1e9 + 7;
//_______________________________________________________________________________________________

int n, k1, k2;
vi adj[MAXN];
int sz[MAXN], isDel[MAXN];
int bit[MAXN];

#define lowbit(u) (u) & -(u)

void update(int u, int val) {
    for (; u <= k2 + 1; u += lowbit(u)) bit[u] += val;
}

int Get(int u) {
    int res = 0;
    for (; u; u -= lowbit(u)) res += bit[u];
    return res; 
}

int GetRange(int l, int r) {
    r++; 
    return Get(r) - Get(l);
}

int countChild(int u, int par = -1) {
    sz[u] = 1; 
    for (int &v : adj[u]) if (!isDel[v] && v != par) {
        sz[u] += countChild(v, u);
    }
    return sz[u];
}

int getCentroid(const int &Sz, int u, int par = -1) {
    for (int &v : adj[u]) if (!isDel[v] && v != par && sz[v] > Sz) {
        return getCentroid(Sz, v, u);
    }
    return u;
}

int64 ans = 0;
int max_depth = 0;

void getSubtree(int u, int par = -1, int depth = 1) {
    if (depth > k2) return ;
    maximize(max_depth, depth);
    ans += GetRange(max(0, k1 - depth), k2 - depth);
    for (int &v : adj[u]) if (!isDel[v] && v != par) { 
        getSubtree(v, u, depth + 1);
    }
}

void updateSubtree(int u, int par = -1, int depth = 1) {
    if (depth > k2) return ;
    update(depth + 1, 1);
    for (int &v : adj[u]) if (!isDel[v] && v != par) { 
        updateSubtree(v, u, depth + 1);
    }
}

void centroid_decomp(int u) {
    int Sz = countChild(u) >> 1;
    int centroid = getCentroid(Sz, u);

    max_depth = 0;

    for (int &v : adj[centroid]) if (!isDel[v]) {
        getSubtree(v, centroid);
        updateSubtree(v, centroid);
    }

    FOR(i, 1, max_depth) update(i + 1, - GetRange(i, i));
    isDel[centroid] = true; 

    for (int &v : adj[centroid]) if (!isDel[v]) {
        centroid_decomp(v);
    }
}

void process(void) {
    cin >> n >> k1 >> k2;
    FOR(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    update(1, 1);
    centroid_decomp(1);

    cout << ans;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    #define name "centroid_b"
    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin); 
        freopen(name".out", "w", stdout);
    }
    //____________________________________________________
    // int t; cin >> t; while (t--)
    process();

    cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
    return 0;
}
