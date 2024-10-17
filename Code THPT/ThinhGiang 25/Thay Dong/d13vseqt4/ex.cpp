// Anh Tuan
// author : anhtun.hi
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define c_bit(i)       __builtin_popcountll(i)
#define Bit(mask, i)    ((mask >> i) & 1)
#define onbit(mask, i)  ((mask) bitor (1LL << i))
#define offbit(mask, i) ((mask) &~ (1LL << i))
#define all(data)      data.begin(), data.end()
#define reset(h, v)   memset(h, v, sizeof h)
#define Forv(i, a)    for(auto& i : a)
#define For(i, a, b)  for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)
using namespace std;

void maximize(auto &a, auto b) {a = max(a, b);}
void minimize(auto &a, auto b) {a = min(a, b);}

//#define int long long

const int dx[] = {0, 0, +1, -1}, dy[] = {-1, +1, 0, 0};
const int MAXN = 2e5  + 10, LOG = 20, base = 311;
const  ll   oo = 1e18;

int n, q, mod, a[MAXN], d[MAXN];

ll st[MAXN << 2];

void fixmod(ll &x){
	if (x < 0) x += mod * mod; x %= mod;
}

struct SegTree {
    ll st[MAXN * 4], lazy[MAXN * 4];
    void down(int id, int l, int r)
    {
        if (!lazy[id] || l == r) return;
        int mid = l + r >> 1;
        (st[id << 1] += (mid - l + 1) * lazy[id]) %= mod, (lazy[id << 1] += lazy[id]) %= mod;
        (st[id << 1 | 1] += (r - mid) * lazy[id]) %= mod, (lazy[id << 1 | 1] += lazy[id]) %= mod;
        lazy[id] = 0;
    }
    void update (int id, int l, int r, int u, int v, ll val)
    {
        if (v < l || r < u) return;
        down(id, l, r);
        if (u <= l && r <= v) {
            (st[id] += 1LL *(r - l + 1) * val) %= mod;
            (lazy[id] += val) %= mod;
            down(id, l, r);
            return;
        }
        int mid = l + r >> 1;
        update(id << 1, l, mid, u, v, val), update(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    ll get (int id, int l, int r, int u, int v)
    {
        if (v < l || r < u) return 0ll;
        down(id, l, r);
        if (u <= l && r <= v) return st[id] % mod;
        int mid = l + r >> 1;
        return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v)) % mod;
    }
} it1;

struct Node{
	ll Min, Max;
	Node(){Min = -oo, Max = oo;}
	Node(ll val){Min = Max = val;}
	friend Node operator +(const Node& x, const Node& y){
		if (x.Min == -oo || x.Max == +oo) return y;
		if (y.Min == -oo || y.Max == +oo) return x;
		Node res; 
		res.Min = min(x.Min, y.Min);
		res.Max = max(x.Max, y.Max);
		return res;
	}
} zero;

struct segtree2{
	Node st[MAXN << 2];
	void update(int id, int l, int r, int u, ll val){
		if (u < l || r < u) return;
		if (l == r) {
			st[id] = Node(val);
			return;
		}
		int mid = l + r >> 1;
		update(id << 1, l, mid, u, val);
		update(id << 1 | 1, mid + 1, r, u, val);
		st[id] = st[id << 1] + st[id << 1 | 1];
	}

	Node get(int id, int l, int r, int u, int v){
		if (v < l || r < u) return zero;
		if (u <= l && r <= v) return st[id];
		int mid = l + r >> 1;
		return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
	}
} it2;

void Solve(){
	cin >> n >> mod >> q;
	For(i, 1, n) cin >> a[i];

	For(i, 1, n){
		it1.update(1, 1, n, i, i, a[i]);
		if (i > 1) it2.update(1, 1, n, i, a[i] - a[i - 1]);
	}
    
	for (int i = 1, op, l, r, c; i <= q; ++i){
		cin >> op >> l >> r;
		if (op == 1){
			cin >> c;
			c %= mod;
			it1.update(1, 1, n, l, r, c);
			ll v0 = it1.get(1, 1, n, l - 1, l - 1);
			ll v1 = it1.get(1, 1, n, l, l);
			if (l - 1 > 0) it2.update(1, 1, n, l, v1 - v0);
			v0 = it1.get(1, 1, n, r, r);
			v1 = it1.get(1, 1, n, r + 1, r + 1);
			if (r + 1 <= n) it2.update(1, 1, n, r + 1, v1 - v0);
		} else {
			// if(i == q - 1) {
			// 	For(i, 1, n) cerr << it1.get(1, 1, n, i, i) << ' ';
			// 	cerr << '\n';
			// }
			if (l == r) cout << 0 << '\n';
			else if (l + 1 == r){
				ll v0 = it1.get(1, 1, n, l, l);
				ll v1 = it1.get(1, 1, n, r, r);
				cout << ((v0 == v1) ? 0 : 1) << '\n';
			}else {
				Node cur = it2.get(1, 1, n, l + 1, r);
				cout << ((cur.Min == cur.Max && cur.Min == 0) ? 0 : 1) << '\n';
			}
		}
	}
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // freopen("d13vseqt4.inp", "r", stdin);
    // freopen("d13vseqt4.out", "w", stdout);
    Solve();
    return 0;
}