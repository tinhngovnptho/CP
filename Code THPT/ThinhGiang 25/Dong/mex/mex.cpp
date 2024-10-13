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

#define name "mex"

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

const int MAXN = 2e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int n, M, q, a[MAXN], seg[4 * MAXN], lazy[4 * MAXN];

struct Node {
    bool flag; 
    int val;
    Node(int x) : val(x), flag(0) {}
    Node() { val = flag = 0; }

    friend Node operator +(const Node &a, const Node &b) {
        Node res; 
        res.flag = (a.flag & b.flag);
        res.val = max(a.val, b.val);
        return res; 
    } 
};

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
        return ;
    }

    int mid = (l + r) >> 1;

    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    

    return 0;
}
