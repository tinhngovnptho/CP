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

#define name "B"

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

const int MAXN = 1e6 + 11; 
// const int MOD = 1e9 + 7; 
const int INF = 1e9 + 11; const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;
// const int BLOCK = 330;

int n, k, a[MAXN];
vi pos[MAXN], f[MAXN];

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    vi ans; 

    // FOR(i, 1, 4)  {
    //     cerr << i << ": ";
    //     for (int x : pos[i]) cerr << x << " ";
    //     cerr << el;
    // }
        
    FOR(val, 1, n) {
        f[val].resize(pos[val].size(), INF);
        REP(i, 0, pos[val].size()) f[val][i] = 2 * i - pos[val][i] - 1; 
        REP(i, 1, pos[val].size()) minimize(f[val][i], f[val][i - 1]);
        REP(i, 0, pos[val].size()) {
            int idx = (2 * i - k) / 2;
            if (k & 1) idx++;
            if (idx < 0 || idx == i) continue;
            // cerr << idx << " " << i << " " << pos[val][idx] << " "<< pos[val][i] << el;
            if (2 * i - pos[val][i] > f[val][idx]) {
                ans.push_back(val);
                break;
            }
        }
    }

    for (int x : ans) cout << x << " ";

    if (ans.size() == 0) cout << -1;

    return 0;
}
