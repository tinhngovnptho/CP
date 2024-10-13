#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
//#define int long long
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
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = (int) 5e5 + 11;
//const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 11;
//const ll INFF = (ll) 1e18 + 11;
//const ll BASE = 311;
const int LOG = 25;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};


int n, k, a[MAXN], st[LOG + 1][MAXN], l[MAXN], r[MAXN];

void build_st(int *d) {
    FOR(i, 1, n + 1) st[0][i] = a[i];
    FOR(i, 1, LOG) {
        for (int j = 1; j + MASK(i) - 1 <= n + 1; ++j) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + MASK(i - 1)]);
        }
    }
    FOR(i, 1, n) {
        int x = i;
        FORD(j, log2(n + 1 - i), 0) {
            if (x + MASK(j) <= n + 1 && st[j][x] <= a[i] + k) x += MASK(j);
        }
        d[i] = x - i;
    }
}



void process(void) {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    a[n + 1] = INF;
    build_st(l);
    reverse(a + 1, a + n + 1);
    build_st(r);
    reverse(r + 1, r + n + 1);
    FOR(i, 1, n) cout << l[i] + r[i] - 1 << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    file("B");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
