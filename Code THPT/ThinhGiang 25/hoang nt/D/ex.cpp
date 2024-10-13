#include <bits/stdc++.h>
 
using namespace std;
 
#define ull unsigned long long
#define db double
#define i32 int32_t  
#define i64 int64_t 
#define ll long long
// 
#define fi first
#define se second
 
 
//                                      #define int long long    // consider carefully
 
 
//
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define pil pair<int, ll> 
#define PAIR make_pair 
//                                      TIME IS LIMITED ...  
#define  rep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define repd(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define repv(v, H) for(auto &v: H)
//                                      REFLECT ON THE PAST ...
#define RESET(c, x) memset(c, x, sizeof(c))
#define MASK(i) (1LL << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1LL)
#define ONBIT(mask, i) ((mask) | (1LL << (i)))
#define OFFBIT(mask, i) ((mask) &~ (1LL << (i)))
#define COUNTBIT __builtin_popcountll
//                                      30 / 1 / 2024 ? love is zero... start from zero 
#define PB push_back
#define EB emplace_back
#define vi vector<int>
#define vll vector<ll>
#define lwb lower_bound
#define upb upper_bound
#define ALL(v) (v).begin(), (v).end()
#define special(H) (H).resize(distance(H.begin(), unique(ALL(H))))
//                                      
#define sp ' ' 
#define nl '\n'
#define yes "YES"
#define no "NO"
#define Log2(n) (63 - __builtin_clzll(n))
#define left __left__
#define right __right__ 
 
//____________________________________________________________________
 
 
template <class X, class Y> bool maximize(X &a, const Y &b) {
    if(a < b) return a = b, true;
    return false;
}
 
template <class X, class Y> bool minimize(X &a, const Y &b) {
    if(a > b) return a = b, true;
    return false;
}
 
const int MOD      = 1000000007;
// const int MOD[2] = {1000000009, 998244353};
 
template<class X> void modmize(X &x, int cur_Mod = MOD) {
    // if(x >= cur_Mod) x -= cur_Mod;
    // if(x < 0) x += cur_Mod;
    x %= MOD;
}
 
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cerr << n << sp, 0)...};
    cerr << endl;
}
 
template <class T, class... C>
void assign(int n, T v, C&&... a) {
    using e = int[];
    e{(a.assign(n, v), 0)...};
}
 
template <class... C>
void resize(int n, C&&... a) {
    using e = int[];
    e{(a.resize(n), 0)...};
}
 
template <class T>
using vector2d = vector<vector<T>>;
template <class T>
using vector3d = vector<vector2d<T>>;
 
template <class T> int ssize(T &a) { return (int) a.size(); }
 
 
//____________________________________________________________________
 
 
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
 
const long long oo = 1e18 + 7;
const int INF      = 2e9;
const int nmax     = 5e3 + 10;
const int MAX      = 2e5;
const int base     = 311;
const db eps       = 1e-6;
const int block    = 500;
 
//____________________________________________________________________
 
 
int n, m;
int a[nmax];
int cnt[nmax];
vector<int> h;
vector3d<int> dp;
 
int mx = 0;
int solve(int i, int c1, int c2) {
    if(i == ssize(h) - 1 && c1 == 0) return 1;
    auto &ret = dp[i][c1][c2];
    if(ret != -1) return ret;
    int cur = 0;
    if(c1 >= 3) modmize(cur += solve(i, c1 - 3, c2));
    if(c1 == 0) modmize(cur += solve(i + 1, c2, (i + 2 < ssize(h)) ? cnt[h[i + 2]] : 0));
    if(c1 && i + 2 < ssize(h) && h[i] + 1 == h[i + 1] && h[i + 1] + 1 == h[i + 2] && c2 >= c1 && cnt[h[i + 2]] >= c1) {
        modmize(cur += solve(i + 1, c2 - c1, cnt[h[i + 2]] - c1));
    }
    return ret = cur;
}
 
void tintingyn() {
 
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> a[i];
        ++cnt[a[i]];
        h.push_back(a[i]);
        maximize(mx, cnt[a[i]]);
    }
 
    sort(ALL(h));
    h.erase(unique(ALL(h)), h.end());
    
    assign(ssize(h), vector2d<int>(mx + 1, vector<int>(mx + 1, -1)), dp);
 
    cout << solve(0, cnt[h[0]], cnt[h[1]]) << nl;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    //________________________________________________________________
 
    #define TASK "d"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
 
    //________________________________________________________________
    
    //  CODE FROM HERE ...! 
 
 
 
 
 
    int num_test = 1; 
    // cin >> num_test;
 
    while(num_test--) {
 
        tintingyn();
 
    }
 
 
    cerr << '\n' << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s\n" << nl;
 
    return 0;
}