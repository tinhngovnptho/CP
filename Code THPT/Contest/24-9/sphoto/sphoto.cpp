#include<bits/stdc++.h>

// Author: Tinhnopro (a.k.a NVT)

using namespace std;

#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define ld long double
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define ONBIT(i, mask) (mask | MASK(i))
#define OFFBIT(i, mask) mask & ~(MASK(i))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = (int) 2e5 + 11;

int n, b[MAXN];

struct Node {
	int active, lazy;
	ll val;

	Node() {
		active = lazy = 0;
		val = 0;
	}

	Node operator + (const Node &other) const {
		Node ans;
		ans.active = active + other.active;
		ans.val = val + other.val;
		return ans;
	}
};

Node seg[4 * MAXN];

#define Left(id) (id << 1)
#define Right(id) (id << 1 | 1)

void push(int id) {
	if (seg[id].lazy == 0) return ; 
	seg[Left(id)].val += seg[Left(id)].active * seg[id].lazy;
	seg[Right(id)].val += seg[Right(id)].active * seg[id].lazy;
	seg[Left(id)].lazy += seg[id].lazy;
	seg[Right(id)].lazy += seg[id].lazy;
	seg[id].lazy = 0;
}

void updateActive(int id, int l, int r, int pos, int x) {
	if (l > pos || r < pos) return ;
	if (l == r) {
		seg[id].active = x;
		seg[id].val = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	push(id);
	updateActive(Left(id), l, mid, pos, x);
	updateActive(Right(id),  mid + 1, r, pos, x);
	seg[id] = seg[Left(id)] + seg[Right(id)];
}

void updateUnique(int id, int l, int r, int u, int v, int x) {
	if (l > v || r < u) return ;
	if (u <= l && r <= v) {
		seg[id].val += seg[id].active * x;
		seg[id].lazy += x;
		return ; 
	}
	int mid = (l + r) >> 1;
	push(id);
	updateUnique(Left(id), l, mid, u, v, x);
	updateUnique(Right(id), mid + 1, r, u, v, x);
	seg[id] = seg[Left(id)] + seg[Right(id)];
}

ll query(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return seg[id].val;
	int mid = (l + r) >> 1;
	push(id);
	return query(Left(id), l, mid, u, v) + query(Right(id), mid + 1, r, u, v);
}

int last[MAXN], Pos[MAXN];

void process(void) {
	cin >> n;
	FOR(i, 1, n) cin >> b[i];
	
	ll ans = 0;

	FOR(i, 1, n) {
		last[i] = Pos[b[i]];
		Pos[b[i]] = i;
	}

	FOR(i, 1, n) {
		updateUnique(1, 1, n, last[last[i]] + 1, last[i] - 1, -1);
		updateUnique(1, 1, n, last[i - 1] + 1, i - 2, 1);
		updateActive(1, 1, n, last[i], 0);
		updateActive(1, 1, n, i, 1);
		ans += query(1, 1, n, last[i] + 1, i - 1); 
	}

	cout << ans;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "sphoto"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
