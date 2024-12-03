#include <bits/stdc++.h>

using namespace std;

#define int long long
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
const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, a[MAXN], st[4 * MAXN];
struct Data{
    int mul, add;
} lz[MAXN * 4];

#define mid(l,r) (l + r) >> 1
#define left(id) (id << 1)
#define right(id) ((id << 1) | 1)


void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = mid(l, r);
    build(left(id), l, mid);
    build(right(id), mid + 1, r);
    st[id] = max(st[left(id)], st[right(id)]);
    lz[id] = {1, 0};
}

void down(int id, int l, int r){
    Data x = lz[id];
    if (x.add == 0 && x.mul == 1)
        return;

    int add = x.add;
    int mul = x.mul;

    if (l != r){
        st[left(id)] = (st[left(id)] * mul + add) % MOD;
        st[right(id)] = (st[right(id)] * mul + add) % MOD;

        lz[left(id)].add *= mul;
        lz[left(id)].add += add;
        lz[left(id)].mul *= mul;
        lz[left(id)].add %= MOD;
        lz[left(id)].mul %= MOD;

        lz[right(id)].add *= mul;
        lz[right(id)].add += add;
        lz[right(id)].mul *= mul;
        lz[right(id)].add %= MOD;
        lz[right(id)].mul %= MOD;
    }

    lz[id] = {1, 0};
}

void update(int id, int l, int r, int u, int v, int add, int mul){
// u .. v : * mul + add
    if (v < l || r < u)
        return;
    down(id, l, r);
    if(u <= l && r <= v){
        st[id] += add;
        st[id] *= mul;
        st[id] %= MOD;

        lz[id].add *= mul;
        lz[id].add += add;
        lz[id].add %= MOD;
        lz[id].mul *= mul;
        lz[id].mul %= MOD;

        down(id, l, r);
        return;
    }

    int mid = mid(l, r);

    update(left(id), l, mid, u, v, add, mul);
    update(right(id), mid + 1, r, u, v, add, mul);

    st[id] = max(st[left(id)], st[right(id)]);
}

int Get(int id, int l, int r, int u, int v){
    if (v < l || r < u)
        return - 1e18;
    down(id, l, r);
    if (u <= l && r <= v){
        return st[id];
    }
    int mid = mid(l, r);
    return max(Get(left(id), l, mid, u, v), Get(right(id), mid + 1, r, u, v));
}

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == '+') {
            int u, v, d;
            cin >> u >> v >> d;
            update(1, 1, n, u, v, d, 1);
        } else if (type == '*') {
            int u, v, d;
            cin >> u >> v >> d;
            update(1, 1, n, u, v, 0, d);
        } else {
            int p;
            cin >> p;
            cout << Get(1, 1, n, p, p) << '\n';
        }
    }
}

signed main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("G");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
