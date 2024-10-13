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

const int MAXN = (int) 5e4 + 11;
//const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, q;
vi seg[4 * MAXN];
pii a[MAXN];

#define Left(id) ((id) << 1)
#define Right(id) ((id) << 1 | 1)

void MergeNode(const vi& leftv, const vi& rightv, vi& v) {
    int i = 0, j = 0;
    while (i < (int) leftv.size() && j < (int) rightv.size()) {
        if (leftv[i] <= rightv[j]) {
            v.push_back(leftv[i++]);
        } else {
            v.push_back(rightv[j++]);
        }
    }
    while (i < (int) leftv.size()) v.push_back(leftv[i++]);
    while (j < (int) rightv.size()) v.push_back(rightv[j++]);
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id].push_back(a[l].se);
        return;
    }

    int mid = (l + r) >> 1;
    build(Left(id), l, mid);
    build(Right(id), mid + 1, r);
    MergeNode(seg[Left(id)], seg[Right(id)], seg[id]);
}

int asked(int id, int l, int r, int u, int v, int k) {
    if (l == r) return a[l].fi;
    int cur = upper_bound(ALL(seg[Left(id)]), v) - lower_bound(ALL(seg[Left(id)]), u);

    int mid = (l + r) >> 1;

    if (cur >= k) return asked(Left(id), l, mid, u, v, k);
    return asked(Right(id), mid + 1, r, u, v, k - cur);
}

void process(void) {
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    build(1, 1, n);
    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;
        cout << asked(1, 1, n, u, v, k) << el;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("F");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
