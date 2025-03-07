/**------------------------------------------
------Author: Tinhnopro (Tinh nop) ----------
---------From: CHV with luv <3 --------------
---------Value = Live + Love ----------------
------------------------------------------**/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second

#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define pb push_back

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

#define Mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | Mask(i))
#define offbit(i, mask) (mask & ~(Mask(i)))
#define cntbit(x) __builtin_popcountll(x)
#define Log2(x) (63 - __builtin_clzll(x))

using namespace std;

using db = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;

template<class X, class Y> bool maximize(X &a, Y b) {
    return a < b ? a = b, 1 : 0;
}

template<class X, class Y> bool minimize(X &a, Y b) {
    return a > b ? a = b, 1 : 0;
}

// const int dx[8] = {+1, -1, +0, +0, +1, -1, +1, -1}, dy[8] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int INF = 1e9 + 11, MAXN = 1e5 + 11, MOD = 1e9 + 7;
// const int64_t INFF = (int64_t) 1e18 + 7;
//_______________________________________________________________________________________________

struct Data {
    int s, type;
    vi v1, v2;

    Data() {
        s = 0;
        type = -1;
    }

    void Resize(void) {
        v1.resize(s);
        v2.resize(s);
    }

    void Read(void) {
        FOR(i, 0, s - 1) cin >> v1[i];
        FOR(i, 0, s - 1) cin >> v2[i];
        cin >> type;
        sort(all(v1));
        sort(all(v2));
    }
};

Data a[MAXN];
int n, k;
unordered_set<int> s;


void process(void) {
    cin >> n >> k;
    FOR(i, 1, k) {
        cin >> a[i].s;
        a[i].Resize();
        a[i].Read();
    }
    FOR(i, 1, k) {
        if (a[i].type == 0) {
            for (int x : a[i].v1) {
                s.insert(x);
            }
            for (int x : a[i].v2) {
                s.insert(x);
            }
        } else {
            if (a[i].type == 1) {
                for (int x : a[i].v1) s.insert(x);

            } else {
                for (int x : a[i].v2) s.insert(x);

            }
        }
    }
    cout << 0;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    #define name "fcoin"
    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //____________________________________________________
    // int t; cin >> t; while (t--)
    process();

    cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
    return 0;
}
