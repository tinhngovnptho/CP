

// author : daohuyenchi



#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define db double
#define i32 int32_t  
#define i64 int64_t 
#define ll long long
// 
#define fi first
#define se second


//                                      #define int long long    // consider carefully


//
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define pil pair<int, ll> 
#define PAIR make_pair 
//                                      TIME IS LIMITED ...  
#define  rep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define repd(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define repv(v, H) for(auto &v: H)
//                                      REFLECT ON THE PAST ...
#define RESET(c, x) memset(c, x, sizeof(c))
#define MASK(i) (1LL << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1LL)
#define ONBIT(mask, i) ((mask) | (1LL << (i)))
#define OFFBIT(mask, i) ((mask) &~ (1LL << (i)))
#define COUNTBIT __builtin_popcountll
//                                      30 / 1 / 2024 ? love is zero... start from zero 
#define PB push_back
#define EB emplace_back
#define vi vector<int>
#define vll vector<ll>
#define lwb lower_bound
#define upb upper_bound
#define ALL(v) (v).begin(), (v).end()
#define special(H) (H).resize(distance(H.begin(), unique(ALL(H))))
//                                      
#define sp ' ' 
#define nl '\n'
#define yes "YES"
#define no "NO"
#define Log2(n) (63 - __builtin_clzll(n))
#define left _left_
#define right _right_ 

//____________________________________________________________________


template <class X, class Y> bool maximize(X &a, const Y &b) {
    if(a < b) return a = b, true;
    return false;
}

template <class X, class Y> bool minimize(X &a, const Y &b) {
    if(a > b) return a = b, true;
    return false;
}

const int MOD      = 1000000007;
// const int MOD[2] = {1000000009, 998244353};

template<class X> void modmize(X &x, int cur_Mod = MOD) {
    if(x >= cur_Mod) x -= cur_Mod;
    if(x < 0) x += cur_Mod;
}

template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cerr << n << sp, 0)...};
    cerr << endl;
}

template <class T, class... C>
void assign(int n, T v, C&&... a) {
    using e = int[];
    e{(a.assign(n, v), 0)...};
}

template <class... C>
void resize(int n, C&&... a) {
    using e = int[];
    e{(a.resize(n), 0)...};
}

template <class T>
using vector2d = vector<vector<T>>;
template <class T>
using vector3d = vector<vector2d<T>>;

template <class T> int ssize(T &a) { return (int) a.size(); }


//____________________________________________________________________


mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

const long long oo = 1e18 + 7;
const int INF      = 2e9;
const int nmax     = 5e5 + 10;
const int MAX      = 2e5;
const int base     = 311;
const db eps       = 1e-6;
const int block    = 500;

//____________________________________________________________________


int h, n;

struct Fac {
    int x, y;

    Fac(int _x = 0, int _y = 1) : 
    x(_x), y(_y) {}

    bool operator < (const Fac &ot) {
        return 1LL * x * ot.y < 1LL * ot.x * y;
    }

    bool operator == (const Fac &ot) {
        return PAIR(x, y) == PAIR(ot.x, ot.y);
    }

    Fac operator + (const Fac &ot) {
        return Fac(x + ot.x, y + ot.y);
    }
} a[nmax];

Fac min_fac(Fac x, Fac y) {
    return x < y ? x : y;
}

struct Node {
    Fac pl, pr, v;

    Node(Fac _pl = Fac(), Fac _pr = Fac()) {
        pl = _pl;
        pr = _pr;
        v = pl + pr;
    }

    Node lf_child() {
        return Node(pl, pl + pr);
    }

    Node rg_child() {
        return Node(pl + pr, pr);
    }

    bool operator == (const Node &ot) {
        return pl == ot.pl && pr == ot.pr && v == ot.v;
    }


};

// Node b[nmax];
// ll g[nmax];
vector<int> f[nmax];
Node root;

void Find(int id, vector<int> &s) {
    auto t = a[id];
    auto cur = root;
    ll res = 1;
    rep(i, 2, h) {
        // print(i);
        if(t == cur.v) {
            break;
        }
        if(t < cur.v) {
            cur = cur.lf_child();
            // res = res * 2;
            s.push_back(0);
        }
        else {
            cur = cur.rg_child();
            // res = res * 2 + 1;
            s.push_back(1);
        }
    }

    // b[id] = cur;
    // assert(cur.v == t);
    // g[id] = res;

}

struct Trie {

    struct Data {

        int child[2];
        // int cnt = 0;

    } node[nmax * 66]; 
    int dem = 0;
    
    Trie() {
        memset(node[0].child, -1, sizeof(node[0].child));
        // node[0].cnt = 0;
    }

    int new_node() {
        ++dem;
        memset(node[dem].child, -1, sizeof(node[dem].child));
        // node[dem].cnt = 0;
        return dem;
    }

    void add(vector<int> &s) {
        int cur = 0;
        // node[cur].cnt++;
        for(auto &k2 : s) {
            int k = k2;
            if(node[cur].child[k] == -1) node[cur].child[k] = new_node();
            cur = node[cur].child[k];
            // node[cur].cnt += 1;
        }
    }

    int Find(int cur) {
        int ok = 0;
        rep(k, 0, 1) {
            if(node[cur].child[k] != -1) {
                ++ok;
            }
        }        
        if(ok == 2) return cur;
        rep(k, 0, 1) {
            if(node[cur].child[k] != -1) {
                return Find(node[cur].child[k]);
            }
        }
        return cur;
    }
    
    int dfs(int cur) {
        int res = 0;
        // int ok = 0;
        rep(k, 0, 1) {
            if(node[cur].child[k] != -1) {
                res += dfs(node[cur].child[k]) + 1;
            }
        }
        return res;
    }

    void get_ans() {

        int cur = 0;

        cout << dfs(cur) << nl;

    }

} trie;

void tintingyn() {

    cin >> h >> n;

    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        a[i] = Fac(x, y);
    }

    root = Node(Fac(0, 1), Fac(1, 0));

    rep(i, 1, n) {
        Find(i, f[i]);
    }
    // return;

    rep(i, 1, n) {
        trie.add(f[i]);

        // repv(v, f[i]) cerr << v << sp;
        // cerr <<nl;
    }



    trie.get_ans();

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //________________________________________________________________

    #define TASK "fracv3"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    //________________________________________________________________
    
    //  CODE FROM HERE ...! 





    int num_test = 1; 
    // cin >> num_test;

    while(num_test--) {

        tintingyn();

    }


    cerr << '\n' << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s\n" << nl;

    return 0;
}