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

#define name "A"
#define int long long 

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

const int MAXN = 1e3 + 11, MAX = 1e6 + 11; 
// const int MOD = 1e9 + 7; 
// const int INF = 1e9 + 11; const ll INFF = (ll) 1e18 + 11;
// const int LOG = 22;
// const int BASE = 311;
// const int BLOCK = 330;

int n, a[MAXN], min_prime[MAX];
ii cost[MAXN][MAXN];

void sieve(int n) {
    FOR(i, 1, n) min_prime[i] = i;
    for (int i = 2; i * i <= n; ++i) if (min_prime[i] == i) {
        for (int j = i * i; j <= n; j += i) if (min_prime[j] == j) min_prime[j] = i;
    }
}

vector<ii> calc(int x) {
    vector<ii> res;
    while (min_prime[x] != 1) {
        int cnt = 0;
        int k = min_prime[x];
        while (x % k == 0){
            x /= k;
            cnt++;
        }
        cnt %= 4; 
        if (cnt == 0) continue;
        res.push_back({k, cnt});
    }
    return res;
}

void preprocess(void) {
    FOR(i, 1, n) FOR(j, i + 1, n) {
        cost[i][j].fi = cost[i][j].se = 1;
        vector<ii> x = calc(a[i]);
        vector<ii> y = calc(a[j]);
        for (ii &k : x) {
            for (ii &l : y) {
                if (k.fi == l.fi) {
                    k.se += l.se;
                }
            }
            k.se %= 4;
            if (k.se == 0) continue;
            cost[i][j].fi *= pow(k.fi, k.se);
            cost[i][j].se *= pow(k.fi, 4 - k.se);
        }
        for (ii &l : y) {
            bool check = true;
            for (ii &k : x) if (k.fi == l.fi) {
                check = false;
                break;
            }
            if (!check) continue;
            cost[i][j].fi *= pow(l.fi, l.se);
            cost[i][j].se *= pow(l.fi, 4 - l.se);
        }
        // cout << a[i] << " " << a[j] << " " << cost[i][j].fi << " " << cost[i][j].se << el;
    }
}

map<int, int> mp;

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    
    sieve(1e6);
    preprocess();

    int cnt = 0;

    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            cnt += mp[cost[i][j].se];
        }
        FOR(j, 1, i - 1) mp[cost[j][i].fi]++;
    }

    cout << cnt; 

    return 0;
}
