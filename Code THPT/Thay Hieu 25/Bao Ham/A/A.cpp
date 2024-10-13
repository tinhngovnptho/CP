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

//const int MAXN = (int) 5e5 + 11;
//const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

ll n, k;
int prime[8] = {2, 3, 5, 7, 11, 13, 17, 19};

void process(void) {
    cin >> n >> k;
    ll cnt = 0;
    int d = 0;
    while(prime[d] <= k) d++;
    FOR(mask, 1, MASK(d) - 1) {
        ll res = 1, bit = 0;
        FOR(i, 0, d - 1) if (BIT(mask, i)) {
            bit++;
            res = 1LL * res * prime[i];
        }
//        cout << res << " " << bit << el;
        if (bit & 1) cnt += n / res;
        else cnt -= n / res;
    }
    cout << n - cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("A");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
