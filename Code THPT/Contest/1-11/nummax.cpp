// Author: tinhnopro (tinh nop)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1011;

string a, b;

int dp[MAXN][MAXN];

void trace(int i, int j) {

}

void run_case(void) {
    cin >> a >> b;
    int n = a.size();
    a = " " + a;
    b = " " + b;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("nummax.inp", "r")) {
        freopen("nummax.inp", "r", stdin);
        freopen("nummax.out", "w", stdout);
    }

    int tests = 1;
    // cin >> tests;
    while (tests--) run_case();
    cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s tinhnop";
}
