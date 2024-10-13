// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define all(v) (v).begin(), (v).end()
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "a"
#define int long long

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, Y b) { 
    return a < b ? a = b, 1 : 0; 
}
template<class X, class Y> bool minimize(X &a, Y b) { 
    return a > b ? a = b, 1 : 0; 
}

// const int MAXN = 1e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int m, n, a[111][111][111]; 

struct Fenwick3D{
    int sz, tree[111][111][111];

    void reset(int n) {
        memset(tree, 0, sizeof tree);
        sz = n;
    }

    void update(int i, int j, int k, int v, int w){
        while (i <= sz){
            int x = j;
            while (x <= sz){
                int y = k;
                while (y <= sz){
                    tree[i][x][y] -= w;
                    tree[i][x][y] += v;
                    y += (y & (-y));
                }
                x += (x & (-x));
            }
            i += (i & (-i));
        }
    }

    int query(int i, int j, int k){
        if (i == 0 || j == 0 || k == 0) return 0;
        int res = 0;
        while (i){
            int x = j;
            while (x){
                int y = k;
                while (y){
                    res += tree[i][x][y];
                    y -= (y & (-y));
                }
                x -= (x & (-x));
            }
            i -= (i & (-i));
        }
        return res;
    }
} bit;

void solve(void) {
    cin >> n >> m;
    bit.reset(n + 1);
    memset(a, 0, sizeof a);
    while (m--) {
        string op;
        cin >> op;
        if (op == "UPDATE") {
            int x, y, z, W;
            cin >> x >> y >> z >> W;
            bit.update(x, y, z, W, a[x][y][z]);
            a[x][y][z] = W;
        } else {
            int x1, y1, z1, x2, y2, z2; 
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            int ans = bit.query(x2, y2, z2);
            ans -= bit.query(x1 - 1, y2, z2);
            ans -= bit.query(x2, y1 - 1, z2);
            ans -= bit.query(x2, y2, z1 - 1);
            ans += bit.query(x1 - 1, y1 - 1, z2);
            ans += bit.query(x1 - 1, y2, z1 - 1);
            ans += bit.query(x2, y1 - 1, z1 - 1);
            ans -= bit.query(x1 - 1, y1 - 1, z1 - 1);
            cout << ans << el;
        }
    }
}

int32_t main(void) {
    //___________________________________
    int t; cin >> t; while(t--) {
        solve();
    }

    return 0;
}
