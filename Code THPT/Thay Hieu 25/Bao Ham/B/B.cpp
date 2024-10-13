#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define ll  long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi  vector<int>
#define fi  first
#define se  second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORX(i, a, b, x) for (int i = (a), _b = (b); i <= _b; i += (x))
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 25;
//const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};


ll n, k, a[MAXN];

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcmOptimize(ll a, ll b) {
    if (a > k || b > k) return k + 1;
    a = a / gcd(a, b);
    /// a / gcd(a, b) * b > k -> a / gcd(a, b) > k / b
    if (a > k / b) return k + 1;
    return a * b;
}

void process(void) {
    cin >> n >> k;
    FOR(i, 0, n - 1) cin >> a[i];
    ll ans1 = 0, ans2 = 0;
    FOR(mask, 1, MASK(n) - 1) {
        ll res = 1, bit = 0;
        FOR(i, 0, n - 1) if (BIT(mask, i)) {
            bit++;
            res = lcmOptimize(res, a[i]);
        }
        if (bit & 1) {
            ans1 += k / res;
            ans2 += bit * (k / res);
        } else {
            ans1 -= k / res;
            ans2 -= bit * (k / res);
        }
    }
    cout << ans1 << " " << ans2;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("B");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
