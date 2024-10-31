/*
    Author: Tinhnopro (Tinh nop)
    From: CHV Phu Tho
 */
#include <bits/stdc++.h>

using namespace std;

template <typename T, int D = 1>
struct vec : public vector<vec<T, D - 1>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};

template <typename T>
struct vec<T, 1> : public vector<T> {
    vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};

template <typename T>
using tpair = pair<T, T>;

#if __cplusplus < 202002L
    template <typename T>
    int ssize(const T &a) { return a.size(); }
#endif // __cplusplus

template <typename T1, typename T2>
bool maximize(T1 &a, T2 b) {
    return a < b ? a = b, true : false;
}

template <typename T1, typename T2>
bool minimize(T1 &a, T2 b) {
    return a > b ? a = b, true : false;
}
// End of tempalte
const int MAXN = 1000;

int64_t n, k;
int64_t dp[MAXN][2];

int64_t solve(int i, int last) {
    if (i == n + 1) return 1;
    if (~dp[i][last]) return dp[i][last];

    int64_t cur = 0;

    if (!last) {
        cur += solve(i + 1, 1);
    } 
    minimize(cur, k + 1);
    cur += solve(i + 1, 0);
    minimize(cur, k + 1);

    return dp[i][last] = cur;
}

void trace(int i, int last) {
    if (i == n + 1) return ;
    if (!last && solve(i + 1, 0) < k) {
        k -= solve(i + 1, 0);
        cout << 1; 
        trace(i + 1, 1);
    } else {
        cout << 0;
        trace(i + 1, 0);
    }
}

void Tinhnopro(void) {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    if (solve(1, 0) < k) {
        cout << "-1";
        return ;
    }
    trace(1, 0);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define name "e"
    if (fopen(name".inp", "r"))
        freopen(name".inp", "r", stdin),
        freopen(name".out", "w", stdout);

    // int t; cin >> t; while (t--)
    Tinhnopro();

    cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s \n";
    return 0;
}
