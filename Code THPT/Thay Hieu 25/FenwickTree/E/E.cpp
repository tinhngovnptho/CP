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

const int MAXN = (int) 5e5 + 11;
//const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, q, bit[MAXN], a[MAXN];

void update_bit(int u, int x) {
    for (; u <= n; u += u & -u) bit[u] += x;
}

int get_bit(int u) {
    int res = 0;
    for (; u; u -= u & -u) res += bit[u];
    return res;
}

void update(int l, int r, int x) {
    update_bit(l, x);
    update_bit(r + 1, -x);
}

void process(void) {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    a[0] = 0;
    FOR(i, 1, n) {
        update(i, i, a[i]);
    }
    cin >> q;
    while (q--) {
        int x; cin >> x;
        int l = 1, r = n, res = n + 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
//            cerr << mid << " " << get_bit(mid) << el;
            if (get_bit(mid) < x) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        cout << res - 1 << el;
        update(1, res - 1, -1);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("E");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
