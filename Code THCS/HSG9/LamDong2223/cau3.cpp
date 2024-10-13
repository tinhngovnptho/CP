#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e5 + 11;

struct Node {
	int64 val, lazy = 0;
} seg[4 * MAXN];

int n, q, a[MAXN];

void build(int id, int l, int r) {
	if (l == r) return void(seg[id].val = a[l]);
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	seg[id].val = seg[id << 1].val + seg[id << 1 | 1].val;
}

void update(int id, int l, int r, int u, int v, int k) {
	if (seg[id].lazy) {
		seg[id].val += (r - l + 1) * seg[id].lazy;
		if (l != r) {
			seg[id << 1].lazy += seg[id].lazy;
			seg[id << 1 | 1].lazy += seg[id].lazy;
		}
		seg[id].lazy = 0;
	}
	if (l > v || r < u) return ;
	if (l >= u && r <= v) {
		seg[id].val += 1LL * k * (r - l + 1);
		if (l != r) {
			seg[id << 1].lazy += k;
			seg[id << 1 | 1].lazy += k;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v, k);
	update(id << 1 | 1, mid + 1, r, u, v, k);
	seg[id].val = seg[id << 1].val + seg[id << 1 | 1].val;
}

int64 query(int id, int l, int r, int u, int v) {
	if (seg[id].lazy) {
		seg[id].val += (r - l + 1) * seg[id].lazy;
		if (l != r) {
			seg[id << 1].lazy += seg[id].lazy;
			seg[id << 1 | 1].lazy += seg[id].lazy;
		}
		seg[id].lazy = 0;
	}
	if (l > v || r < u) return 0;
	if (l >= u && r <= v) return seg[id].val;
	int mid = (l + r) >> 1;
	return query(id << 1, l, mid, u, v) + query(id << 1 | 1, mid + 1, r, u, v);
}

void process(void) {
	cin >> n >> q;
	FORE(i, 1, n) cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			int k; cin >> k;
			update(1, 1, n, l, r, k);
		} else {
			cout << query(1, 1, n, l, r) << "\n";
		}
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("cau3");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
