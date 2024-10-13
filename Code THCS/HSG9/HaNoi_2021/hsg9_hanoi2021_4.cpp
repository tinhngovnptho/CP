#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define vt vector
#define pub push_back
#define ii pair<int, int>
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template<class T> bool umin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

const ll oo  = 1e18;
const int INF = 1e9 + 1e8 + 1e7;
const int MOD = 1e9 + 7;
const int mxN = 5011;

int h[mxN][mxN], c[mxN][mxN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    file("ITABLE");

    int n, q;
    cin >> n >> q;
    while (q--) {
        int k, rc, x, y;
        cin >> k >> rc >> x >> y;
        if (k == 1) {
            h[rc][x]++;
            h[rc][y+2]++;
            if ((y - x + 1) % 2 == 1) {
                h[rc][x + (y - x + 1) / 2 + 1] -= 2;
            }
            else {
                h[rc][x + (y - x + 1) / 2]--;
                h[rc][x + (y - x + 1) / 2 + 1]--;
            }
        }
        else {
            c[x][rc]++;
            c[y+2][rc]++;
            if ((y - x + 1) % 2 == 1) {
                c[x + (y - x + 1) / 2 + 1][rc] -= 2;
            }
            else {
                c[x + (y - x + 1) / 2][rc]--;
                c[x + (y - x + 1) / 2 + 1][rc]--;
            }
        }
    }
    for (int i = 1; i <= n + 2; ++i) {
        for (int j = 1; j <= n + 2; ++j) {
            h[i][j] += h[i][j-1];
            c[i][j] += c[i-1][j];
        }
    }
    for (int i = 1; i <= n + 2; ++i) {
        for (int j = 1; j <= n + 2; ++j) {
            h[i][j] += h[i][j-1];
            c[i][j] += c[i-1][j];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int u, v;
        cin >> u >> v;
        cout << h[u][v] + c[u][v] << "\n";
    }
}
