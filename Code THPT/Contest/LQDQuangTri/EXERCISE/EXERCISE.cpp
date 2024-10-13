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

const int MAXN = 311;
const int MOD = 1e9 + 7;

int n;
ll a[MAXN], dp[MAXN][MAXN];

bool check(ll x, ll y) {
    ll d = x * y;
    ll sqrt_d = trunc(sqrt(d));
    return (sqrt_d * sqrt_d == d);
}

namespace Sub1 {

    void solve(void) {
        int cnt = 1;
        vector<int> v;
        FOR(i, 1, n) v.push_back(i);
        FOR(i, 0, SZ(v) - 2) {
            if (check(a[v[i]], a[v[i + 1]])) {
                cnt = 0;
                break;
            }
        }
        while (next_permutation(ALL(v))) {
            bool d = true;
            FOR(i, 0, SZ(v) - 2) {
                if (check(a[v[i]], a[v[i + 1]])) {
                    d = false;
                    break;
                }
            }
            cnt += d;
        }
        cout << cnt;
    }
}

namespace Sub2 {

}

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    if (n <= 10) return void(Sub1::solve());
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "EXERCISE"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

//    int t; cin >> t; while (t--)
    process();

    return 0;
}
