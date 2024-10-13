// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MAXN = 1e6 + 11, INF = 1e18 + 11;

int n, m;
long long a[MAXN];
struct Node {
	long long val, lazy = 0;
} seg[4 * MAXN];

void push(int id) {
	if (seg[id].lazy != 0) {
		seg[id << 1].lazy += seg[id].lazy;
		seg[id << 1].val += seg[id].lazy;
		seg[id << 1 | 1].lazy += seg[id].lazy;
		seg[id << 1 | 1].val += seg[id].lazy;
		seg[id].lazy = 0;
	}
}

long long getmin(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return INF;
	if (u <= l &&  r <= v) return seg[id].val;
	int mid = (l + r) >> 1;
	push(id);
	return min(getmin(id << 1, l, mid, u, v),
				getmin(id << 1 | 1, mid + 1, r, u, v));
}

void update(int id, int l, int r, int u, int v, int val) {
	if (l > v || r < u) return ;
	if (u <= l && r <= v) {
		seg[id].val += val;
		seg[id].lazy += val;
		return ;
	}
	int mid = (l + r) >> 1;
	push(id);
	update(id << 1, l, mid, u, v, val);
	update(id << 1 | 1, mid + 1, r, u, v, val);
	seg[id].val = min(seg[id << 1].val, seg[id << 1 | 1].val);
}

void build(int id, int l, int r) {
	if (l == r) {
		return void(seg[id].val = a[l]);
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	seg[id].val = min(seg[id << 1].val, seg[id << 1 | 1].val);
}

void process(void) {
	cin >> n >> m;
	FORE(i, 1, n) cin >> a[i];
	build(1, 1, n);
	FORE(i, 1, m) {
		int k, l, r; cin >> k >> l >> r;
		if (getmin(1, 1, n, l, r) < k) {
			cout << -1 << "\n" << i;
			return ;
		}
		update(1, 1, n, l, r, -k);
	}
	cout << 0;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
