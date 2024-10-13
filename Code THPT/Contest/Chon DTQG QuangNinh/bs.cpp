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

const int MAXN = 1e5 + 11; 

int n, pref[MAXN];
string s;

namespace Sub1 {
    void solve(void) {
        ll cnt = 0;
        FOR(i, 1, n) FOR(j, i, n) {
            if ((j - i + 1) % (pref[j] - pref[i - 1]) == 0) cnt++;
        }
        cout << cnt;
    }
};

void process(void) {
    cin >> s;
    n = SZ(s);
    s = " " + s;
    FOR(i, 1, n) pref[i] = pref[i - 1] + s[i] - '0';
    if (n <= 1000) return void(Sub1::solve());
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "bs"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
