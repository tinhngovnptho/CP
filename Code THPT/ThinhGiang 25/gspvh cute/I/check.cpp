// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()
#define szv(v) ((int)(v).size())
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "check"

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

template<class T> using vector2d = vector<vector<T>>;

// const int MAXN = 5e5 + 11; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7;
// const int INF = 1e9 + 11; 
// const ll INFF = 1e18 + 11; 

int n, x0, y0;
map<ii, int> r, b, q;

void init(map<ii, int> &m, const int &x, const int &y) {
    if (x == x0) {
        ii l = {0, 1};
        if (y < y0) l.se = -1;
        if (m.find(l) != m.end()) minimize(m[l], abs(y - y0));
        else m[l] = abs(y - y0);
    } 
    if (y == y0) {
        ii l = {1, 0};
        if (x < x0) l.fi = -1;
        if (m.find(l) != m.end()) minimize(m[l], abs(x - x0));
        else m[l] = abs(x - x0);
    } 
    if (abs(y - y0) == abs(x - x0)) {
        if (x > x0) {
            ii k = {1, 1};
            if (y < y0) k.se = -1;
            if (m.find(k) != m.end()) {
                minimize(m[k], abs(x - x0));
            } else m[k] = abs(x - x0);
        } else {
            ii k = {-1, 1};
            if (y < y0) k.se = -1;
            if (m.find(k) != m.end()) maximize(m[k], abs(x - x0));
            else m[k] = abs(x - x0);
        }
    }
} 

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int cx[] = {1, 1, -1, -1};
int cy[] = {1, -1, 1, -1};

void solve(void) {
    while (cin >> n) {
        if (n == -1) break;
        r.clear(); b.clear(); q.clear();
        cin >> x0 >> y0;
        FOR(i, 1, n) {
            char op; int x, y;
            cin >> op >> x >> y;
            if (op == 'R') {
                init(r, x, y);
            } else if (op == 'B') {
                init(b, x, y);
            } else {
                init(q, x, y);
            }
        } 

        // for (auto x : r) {
        //     cout << x.fi.fi << " " << x.fi.se << " " << x.se << el;
        // }
        // cout << el;

        // for (auto x : b) {
        //     cout << x.fi.fi << " " << x.fi.se << " " << x.se << el; 
        // }

        // cout << el;

        bool check = false;

        FOR(i, 0, 3) {
            ii l = {dx[i], dy[i]};
            if (b.find(l) == b.end() && (r.find(l) != r.end() || q.find(l) != q.end())) {
                cout << "YES\n";
                check = true;
                break;
            }
            if (b.find(l) != b.end()&& (r.find(l) != r.end() || q.find(l) != q.end())) {
                int ret = b[l];
                if (r.find(l) != r.end()) minimize(ret, r[l]);
                if (q.find(l) != q.end()) minimize(ret, q[l]);
                if (ret != b[l]) {
                    cout << "YES\n";
                    check = true;
                    break;
                }
            }
        }
        if (check) continue;

        FOR(i, 0, 3) {
            ii l = {cx[i], cy[i]};
            if (r.find(l) == r.end() && (b.find(l) != b.end() || q.find(l) != q.end())) {
                cout << "YES\n";
                check = true;
                break;
            }
            if (r.find(l) != r.end()&& (b.find(l) != b.end() || q.find(l) != q.end())) {
                int ret = r[l];
                if (b.find(l) != b.end()) minimize(ret, b[l]);
                if (q.find(l) != q.end()) minimize(ret, q[l]);
                if (ret != r[l]) {
                    cout << "YES\n";
                    check = true;
                    break;
                }
            }
        }

        if (!check) cout << "NO\n";
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
    // int t; cin >> t; while (t--)
    solve();

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
