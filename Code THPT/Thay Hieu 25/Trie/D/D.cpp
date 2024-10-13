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
//#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((i) & MASK(x))
#define ONBIT(x, i) ((i) | MASK(x))
#define OFFBIT(x, i) ((i) & ~MASK(x))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 2e5 + 11;

int n, a[MAXN];

struct Trie {
    struct Node {
        Node* child[2];
        int exist;
        Node() {
            child[0] = child[1] = NULL;
            exist = 0;
        }
    };

    Node* root;
    Trie() {
        root = new Node();
    }

    void add(const int &x) {
        Node* p = root;
        FORD(i, 31, 0) {
            int c = (x >> i) & 1;
            if (p->child[c] == NULL) p->child[c] = new Node();
            p = p->child[c];
        }
        p->exist = x;
    }

    int calc(int x) {
        Node* p = root;
        FORD(i, 31, 0) {
            int c = (x >> i) & 1;
            if (p->child[1 ^ c] != NULL) c = 1 ^ c;
            p = p->child[c];
        }
        return p->exist ^ x;
    }
} trie;

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    int ans = 0;
    FOR(i, 1, n) {
       trie.add(a[i]);
       ans = max(ans, trie.calc(a[i]));
    }
    cout << ans;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "D"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

//    int t; cin >> t; while (t--)
    process();

    return 0;
}
