// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()
#define szv(v) ((int)(v).size())
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "river"

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

template<class T> using vector2d = vector<vector<T>>;

const int MAXN = 1e6 + 11; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7;
const int INF = 1e9 + 11; 
// const ll INFF = 1e18 + 11; 

int n, M, j, d[MAXN];

int cntJump(ll x) {
    int j = 1;
    int ret = 1;
    ll sum = d[0];
    if (sum > x) return INF;  
    FOR(i, 1, n - 1) {
        if (sum + d[i] <= x) {
            sum += d[i];
        } else {
            ret++;
            sum = d[i];
            if (sum > x) return INF; 
        }
    } 
    return ret; 
}

void solve(void) {
    cin >> n >> M >> j;
    FOR(i, 0, n - 1) d[i] = 1 + 1LL * i * i % M;

    ll l = 1, r = 1e18 + 11, res = -1;

    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (cntJump(mid) <= j) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1; 
    }

    cout << res; 
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    // int t; cin >> t; while (t--)
    solve();

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
