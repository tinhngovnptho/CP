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

#define name "fracv"

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

const int MAXN = 5e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

struct Speacialfrac {
    int a, b;
    Speacialfrac(int _a, int _b) : a(_a), b(_b) {}
    Speacialfrac() {
        a = b = 1;
    }

    friend Speacialfrac operator+(const Speacialfrac &a, const Speacialfrac &b) {
        Speacialfrac res;
        res.a = a.a + b.a;
        res.b = a.b + b.b;
        return res;
    }

    bool operator <(const Speacialfrac &other) {
        return 1ll * a * other.b < 1ll * other.a * b; 
    }

    bool operator !=(const Speacialfrac &other) {
        return 1ll * a * other.b != 1ll * other.a * b;
    }

    bool operator ==(const Speacialfrac &other) {
        return 1ll * a * other.b == 1ll * other.a * b;
    }
    void operator&=(const Speacialfrac &other) {
        a = other.a;
        b = other.b;
    }

    void print(void) {
        cout << a << " " << b << el;
    }
};

struct Trie {
    struct Node {
        int child[2];
        int sz = 1;
    } nodes[MAXN * 70];

    int cur = 0;

    Trie() {
        memset(nodes[0].child, -1, sizeof nodes[0].child);
    }

    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof nodes[cur].child);
        return cur;
    }

    void add(const Speacialfrac &a) {
        int pos = 0;
        Speacialfrac Left(0, 1), Right(1, 0), res(1, 1);
        while (res != a) {
            if (res < a) {
                if (nodes[pos].child[1] == -1) nodes[pos].child[1] = new_node();
                pos = nodes[pos].child[1];
                Left = res;
                res = res + Right;
            } else {
                if (nodes[pos].child[0] == -1) nodes[pos].child[0] = new_node();
                pos = nodes[pos].child[0];
                Right = res;
                res = Left + res; 
            }
        }
    }

    void dfs(int pos) {
        FOR(i, 0, 1) {
            if (nodes[pos].child[i] != -1) {
                dfs(nodes[pos].child[i]);
                nodes[pos].sz += nodes[nodes[pos].child[i]].sz;
            }
        }
    }

    int find_deg(void) {
        int pos = 0;
        while (true) {
            if ((nodes[pos].child[0] != -1) && (nodes[pos].child[1] != -1)) break;
            if ((nodes[pos].child[0] == -1) && (nodes[pos].child[1] == -1)) break; 
            FOR(i, 0, 1) {
                if (nodes[pos].child[i] != -1) {
                    // cerr << '1';
                    pos = nodes[pos].child[i];
                    break;
                }
            }
            // cerr << endl;
        }
        return nodes[pos].sz;
    }
    
} trie;

int h, k;
Speacialfrac d[MAXN];

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> h >> k;

    FOR(i, 1, k) {
        int a, b; cin >> a >> b;
        trie.add(Speacialfrac(a, b));
    }

    trie.dfs(0);

    cout << trie.find_deg() - 1;
    return 0;
}
