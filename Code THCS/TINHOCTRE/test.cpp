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

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
const long long INF = 1e18 + 11;

int n, L, R, a[MAXN];
long long sum[MAXN], seg[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) return void(seg[id] = a[l]);
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

long long getMax(int id, int l, int r, int u, int v) {
    if (l == r)
}

void process(void) {
    cin >> n >> L >> R;
    FORE(i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    build(1, 1, n);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("test");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
