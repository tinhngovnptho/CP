/*
    Author: tinhnopro (ngh)
    link: https://codeforces.com/group/OgDyRcm8ue/contest/552261/problem/B
*/
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPN(i, n) for (int i = 1; i <= (int) (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define all(v) (v).begin(), (v).end()

#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "A"

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

const int MAXN = 4e3 + 11; 
// const int MOD = 1e9 + 7; 
// const int INF = 1e9 + 11; 
const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;

int n, m, k, a[MAXN][MAXN];
ll sum[MAXN][MAXN]; 

ll sumSquare(const int &i, const int &j, const int &res) {
    int x = i + res - 1;
    int y = j + res - 1;
    if (x > n) return INFF;
    if (y > m) return INFF;
    return sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1];
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    FOR(i, 1, n) FOR(j, 1, m) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }

    int res = 0;
    FOR(i, 1, n) FOR(j, 1, m) {
        while (sumSquare(i, j, res + 1) <= k) res++; 
    }

    cout << res << el; 

    return 0;
}
