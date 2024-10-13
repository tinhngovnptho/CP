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
//#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((i) & MASK(x))
#define ONBIT(x, i) ((i) | MASK(x))
#define OFFBIT(x, i) ((i) & ~MASK(x))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 3e5 + 11;

int n, d, a[MAXN];

namespace Sub5 {

    void solve(void) {
        vector<int> v;
        v.push_back(a[1]);
        FOR(i, 2, n) {
            if (a[i] > v.back()) v.push_back(a[i]);
            int l = lower_bound(ALL(v), a[i]) - v.begin();
            v[l] = a[i];
        }
        cout << SZ(v);
    }

}

namespace Sub2 {

    void Compress(void) {
        vi v;
        FOR(i, 1, n) v.push_back(a[i]);
        sort(ALL(v));
        v.resize(unique(ALL(v)) - v.begin());
        FOR(i, 1, n) a[i] = lower_bound(ALL(v), a[i]) - v.begin() + 1;
    }

    int dp[411][411];

    void solve(void) {
        Compress();

        dp[1][1] = 1;
        FOR(i, 2, n) {
            FOR(j, max(1, i - d), i - 1) FOR(mx, 1, n) {
                if (a[i] > mx) maximize(dp[i][a[i]], dp[j][mx] + 1);
                else {
                    maximize(dp[i][mx], dp[j][mx]);
                }
            }
        }
        int ans = 0;
        FOR(i, 1, n) FOR(mx, 1, n) maximize(ans, dp[i][mx]);
        cout << ans;
    }
}

void process(void) {
    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];
    if (d == n) return void(Sub5::solve());
    Sub2::solve();
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "IMPARR"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

//    int t; cin >> t; while (t--)
    process();

    return 0;
}
