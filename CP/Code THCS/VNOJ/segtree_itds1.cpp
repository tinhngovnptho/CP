#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;
typedef __int128_t int128;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e5 + 11;

int n, q, a[MAXN];
set<int> seg[4 * MAXN];

void add(int id, int l, int r, int pos, int val) {
	seg[id].insert(val);
	if (l == r) return ;
	int mid = (l + r) >> 1;
	if (p <= mid) add(id << 1, l, mid, pos, val);
	else add(id << 1 | 1, mid + 1, r, pos, val);
}

int query(int id, int l, int r, int u, int v, int k) {
	if (l > v || r < u) return -INF;
	if (u <= l && r <= v) return
}

void process(void) {
	cin >> n >> q;
	FORE(i, 1, n) cin >> a[i];
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int pos, val; cin >> pos >> val;
		} else {
			int L, R, k; cin >> L >> R >> k;
		}
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("segtree_itds1");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
