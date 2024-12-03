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

#define name "book1"

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

const int MAXN = 1e7 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int n, k, a[MAXN]; 

bool check(ll x) {
    int cnt = 0;
    for (int i = 1; i <= n; ) {
        ll sum = 0;
        int j = i;
        while (sum + a[j] <= x) {
            sum += a[j];
            j++;
            if (j > n) break;
        }
        ++cnt;
        if (i == j) return false;
        i = j;
    }
    // cout << x << " " << cnt << el;
    return  cnt <= k;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    ll l = 1, r = 1e18 + 11, res = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1LL;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    } 

    cout << res;

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
