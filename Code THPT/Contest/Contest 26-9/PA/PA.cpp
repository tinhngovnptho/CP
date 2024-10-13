#include<bits/stdc++.h>

// Author: Tinhnopro (a.k.a NVT)

using namespace std;

#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define ld long double
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define ONBIT(i, mask) (mask | MASK(i))
#define OFFBIT(i, mask) mask & ~(MASK(i))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAX  = 1e6 + 11;

int n, a[222], dp[MAX];

void process(void) {
    cin >> n;
    memset(dp, 0, sizeof dp);
    ll sum = 0;
    FOR(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    dp[0] = 1;
    FOR(i, 1, n) {
        FORD(j, sum, a[i]) if (dp[j - a[i]]) {
            dp[j] = 1;
        }
    }
    ll res = 0;
    ll S = 0;
    FOR(i, 1, sum) if (dp[i]) {
        res++;
    }
    res--;
    cout <<  sum * 2 + 1 + res * (sum - 1) - res * (res - 1) / 2; 
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "PA"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
