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

#define name "knight"

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

const int MAXN = 2101; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7;
// const int INF = 1e9 + 11; 
// const ll INFF = 1e18 + 11; 

const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, -2, 2, 1, -1, 1, -1};

int d[MAXN][MAXN];

void preprocess(void) {
    memset(d, -1, sizeof d);
    queue<ii> q; 
    q.push({100, 100});
    d[100][100] = 0;
    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se; 
        q.pop();
        FOR(i, 0, 7) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx <= 2100 && yy >= 0 && yy <= 2100 && d[xx][yy] == -1) {
                d[xx][yy] = d[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
}

void solve(void) {
    preprocess();
    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        int x = abs(x1 - x2);
        int y = abs(y1 - y2);
        cout << d[x + 100][y + 100] << " ";
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
