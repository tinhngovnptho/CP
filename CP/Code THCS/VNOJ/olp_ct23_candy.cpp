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
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MAXN = 2e5 + 11;

int n, q, a[MAXN];
long long seg[4*MAXN][10];

bool contain(int a, int k) {
	while (a) {
		if (a % 10 == k) return true;
		a /= 10;
	}
	return false;
}

long long getUpdate(int i, int k) {
	if (i % k == 0 || contain(i, k)) {
		return 2 * a[i];
	}
	return a[i];
}

void build(int id, int l, int r) {
	if (l == r) {
		FORE(i, 1, 9) seg[id][i] = getUpdate(l, i);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	FORE(i, 1, 9) seg[id][i] = seg[2 * id][i] + seg[2 * id + 1][i];
}

void update(int id, int l, int r, int u) {
	if (u < l || r < u) {
		return ;
	}
	if (l == r) {
		FORE(i, 1, 9) seg[id][i] = getUpdate(u, i);
		return ;
	}
	int mid = (l + r) / 2;
	update(2 * id, l, mid, u);
	update(2 * id + 1, mid + 1, r, u);
	FORE(i, 1, 9) seg[id][i] = seg[2 * id][i] + seg[2 * id + 1][i];
}

long long query(int id, int l, int r, int u, int v, int k) {
	if (l > v || r < u) return 0LL;
	if (u <= l && r <= v) return seg[id][k];
	int mid = (l + r) / 2;
	return query(2 * id, l, mid, u, v, k) + query(2 * id + 1, mid + 1, r, u, v, k);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	cin >> n >> q;
	FORE(i, 1, n) cin >> a[i];
	build(1, 1, n);
//	FORE(i, 1, n * 4) cout << seg[i][1] << " ";
//	cout << "\n";
	while(q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, c;
			cin >> i >> c;
			a[i] = c;
			update(1, 1, n, i);
//			FORE(j, 1, 4*n) cout << seg[j][1] << " ";
		} else {
			int L, R, k;
			cin >> L >> R >> k;
			cout << query(1, 1, n, L, R, k) << "\n";
		}
	}

	return 0;
}
