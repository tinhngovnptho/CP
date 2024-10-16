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

#define name "knight"

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

const int MAXN = 6005; // const int MAX = 1e6 + 11;
const int MOD = 998244353;
// const int INF = 1e9 + 11; 
// const ll INFF = 1e18 + 11; 

int dp[MAXN][MAXN];

const int lim = 6000;
const int zero = 2000;
const int dx[] = {2, 2, 1, -1};
const int dy[] = {-1, 1, 2, 2};

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int x1, y1, x2, y2, x, y; 

void solve(void) {
    cin >> x1 >> y1 >> x2 >> y2;
    x = x2 - x1;
    y = y2 - y1; 

    cout << dp[x + zero][y + zero] << el;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________

    dp[zero][zero] = 1;
    int y;

    FOR(sum, 2 * zero, 2 * lim) {
        FOR(x, max(0, sum - lim), min(sum, lim)) {
            y = sum - x;
            FOR(k, 0, 3) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (i < 0 || i > lim || j < 0 || j > lim) continue;
                add(dp[i][j], dp[x][y]);
            } 
        }
    }

    int t; cin >> t; while (t--)
    solve();

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
