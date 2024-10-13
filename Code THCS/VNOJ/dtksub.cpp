#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<ll, ll>
#define vt vector
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (ll) (x) * (x)
#define FOR(i, a, b) for (__typeof(a) i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (__typeof(a) i = (b), _a = (a); i >= _a; --i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template<class T> bool umin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll oo  = 1e18;
const int MOD = 1e9 + 7;
const int mxN  = 2e5 + 11;
const int mxVal = 1e6 + 11;
const int base = 31;

int n, k;
string s;

ll pw[mxN], hashS[mxN];
unordered_map<ll, int> cnt;

void init() {
        pw[0] = 1;
        FOR(i, 1, n) pw[i] = pw[i-1] * base % MOD;
        FOR(i, 1, n) hashS[i] = (hashS[i-1] * base + s[i] - 'a' + 1) % MOD;
}

ll getHash(int i, int j) {
        return (hashS[j] - hashS[i-1] * pw[j-i+1] + MOD * MOD) % MOD;
}

bool check(int l) {
        if(l < 1 || l > n) return false;
        FOR(i, l, n) {
                ll x = getHash(i - l + 1, i);
                cnt[x]++;
                if (cnt[x] >= k)
                        return true;
        }
        return false;
}

signed main(void) {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        file("");
        cin >> n >> k >> s;
        s = " " + s;
        init();
        int l = 1, r = n, ans = 0;
        while (l <= r) {
                int mid = (l + r) / 2;
                if (check(mid)) {
                        ans = max(ans, mid);
                        l = mid + 1;
                } else
                        r = mid - 1;
        }
        cout << ans;

}


/**-----------------------------------------------
---------------Author: tinhnopro------------------
---------------While (!Die) Code(); <3------------
-----------------------------------------------**/
