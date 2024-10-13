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

#define name "D"

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
const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int n, m, cnt[MAXN];
vi h;
vector<vector<vi>> dp;

void add(int &a, int b) {
    a += b;
    a %= MOD;
}

int solve(int i, int c1, int c2) {
    if (i == h.size() - 1 && c2 == 0){
         return 1;
    }

    int &ret = dp[i][c1][c2];
    if (ret != -1) return ret;

    int cur = 0;
    
    if (c2 >= 3) add(cur, solve(i, c1, c2 - 3));
    
    if (c2 == 0) add(cur, solve(i + 1, (i + 2 < h.size()) ? cnt[h[i + 2]] : 0, c1));
    
    if (c2 && i + 2 < h.size() && h[i] + 1 == h[i + 1] && h[i + 1] + 1 == h[i + 2] && c1 >= c2 && cnt[h[i + 2]] >= c2) {
        add(cur, solve(i + 1, cnt[h[i + 2]] - c2, c1 - c2));
    }

    return ret = cur; 
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> m;
    int mx = -1;
    FOR(i, 1, n) {
        int x; cin >> x;
        cnt[x]++;
        maximize(mx, cnt[x]);
        h.push_back(x);
    }

    sort(all(h));
    h.resize(distance(h.begin(), unique(all(h))));

    dp.assign(h.size() + 1, vector<vi>(mx + 1, vector<int>(mx + 1, -1)));

    cout << solve(0, cnt[h[1]], cnt[h[0]]);

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
