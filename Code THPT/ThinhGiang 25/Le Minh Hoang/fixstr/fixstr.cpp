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

#define name "fixstr"

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

const int MAXN = 1e6 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

struct Node {
    int open, close;
    
    Node() {
        open = close = 0;
    }

    Node(int o, int c) : open(o), close(c) {}

    friend Node operator+(const Node &a, const Node &b) {
        Node res;
        int tmp = min(a.open, b.close);
        res.open = a.open + b.open - tmp;
        res.close = a.close + b.close - tmp;
        return res;
    }
};

Node seg[4 * MAXN];
string a;

void build(int id, int l, int r) {
    if (l == r) {
        if (a[l] == '(') seg[id] = {1, 0};
        else seg[id] = {0, 1};
        return ;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

void update(int id, int l, int r, int pos) {
    if (pos == -1) return ;
    if (l > pos || r < pos) return ;
    if (l == r) {
        swap(seg[id].close, seg[id].open);
        return ;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos);
    update(id << 1 | 1, mid + 1, r, pos);

    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

Node query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return {0, 0};
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, u, v) + query(id << 1 | 1, mid + 1, r, u, v);
}

struct Query {
    char op;
    int i, j;

    Query() {
        i = j = 0;
    }

    Query(int _i, int _j) : i(_i), j(_j) {}
    
};

vector<int> treeQuery[MAXN];
Query queries[MAXN];
int res[MAXN], n;

void dfs(int u) {
    if (queries[u].op == 'C') {
        update(1, 1, n, queries[u].i);
    } else if (queries[u].op == 'Q') {
        Node ans = query(1, 1, n, queries[u].i, queries[u].j);
        res[u] = ans.close + ans.open;
    }

    for (int v : treeQuery[u]) {
        dfs(v);
    }

    if (queries[u].op == 'C') {
        update(1, 1, n, queries[u].i);
    }
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    int q;
    cin >> a >> q;
    n = a.size();
    a = " " + a;
    build(1, 1, n);

    FOR(i, 1, q) {
        cin >> queries[i].op;
        if (queries[i].op == 'Q') {
            cin >> queries[i].i >> queries[i].j;
            treeQuery[i - 1].push_back(i);
        } else if (queries[i].op == 'U') {
            cin >> queries[i].i;
            treeQuery[queries[i].i - 1].push_back(i);
        } else {
            cin >> queries[i].i;
            treeQuery[i - 1].push_back(i);
        } 
    }
    dfs(0);

    FOR(i, 1, q) if (queries[i].op == 'Q') cout << res[i] << el;

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
