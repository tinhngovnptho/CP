#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e6 + 11, MAX = 1e6 + 11;
const int MOD = 123456789;
//const int INF = 1e9 + 11;

int m;

int cntFac[MAXN], min_prime[MAXN], v[MAXN];

void sieve(int n) {
    FORE(i, 2, sqrt(n)) if (min_prime[i] = i) {
        FORE(j, i, n / i) if (min_prime[i * j] == 0) min_prime[i * j] = i;
    }
    FORE(i, 2, n) if (min_prime[i] == 0) min_prime[i] = i;
}

void factor(int n) {
    while (n != 1) {
        cntFac[min_prime[n]]++;
        n /= min_prime[n];
    }
}

void process(void) {
    cin >> m;
    for (int i = 1, d = 0; i <= m;  ++i) if (i % 10 != 4) v[d++] = i;
    sieve(m);
//    FORE(i, 1, m) cout << min_prime[i] << " ";
    FOR(i, 0, m) factor(v[i]);
    int ans = 1;
    FORE(i, 1, m) if (cntFac[i]) ans = 1LL * ans * (cntFac[i] + 1) % MOD;
    cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
//	file("");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
