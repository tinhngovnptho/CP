#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

const int MAXN = 1011;

int a[MAXN][MAXN];
int n, m;

bool maximize(int &x, int y) {
    return x < y ? x = y, 1 : 0;
}

namespace Sub1 {
    int pref[MAXN][MAXN];

    void solve(void) {
        FOR(i, 1, n) FOR(j, 1, m) {
            pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }

        int cnt = 0, maxrec = -1;

        FOR(x1, 1, n) FOR(y1, 1, m) {
            FOR(x2, x1, n) FOR(y2, y1, m) {
                int d = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];

                if (d == 0) {
                    if (maximize(maxrec, (x2 - x1 + 1) * (y2 - y1 + 1))) {
                        cnt = 1;
                    } else if (maxrec == (x2 - x1 + 1) * (y2 - y1 + 1)) {
                        cnt++;
                    }
                }
            }
        }
        cout << maxrec << " " << cnt;
    }
}

namespace Sub2 {

}

void process(void) {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    if (n <= 100 && m <= 100) return void(Sub1::solve());
    Sub2::solve();
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "MAXREC"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
//    int t; cin >> t; while(t--)
    process();

    return 0;
}
