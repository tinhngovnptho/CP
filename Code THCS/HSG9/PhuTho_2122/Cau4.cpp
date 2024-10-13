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
const int mxN = 1e6+11, mxM = 1e4+11;

int firstC[10], cnt[mxN], a[mxM], b[mxM], first[mxN];
int n, m, p, x;

int firstDigt(int x) {
    if (first[x] != -1) return first[x];
    string s = to_string(x);
    return first[x] = s[0] - '0';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(first, -1, sizeof first);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= p; ++i) {
        cin >> x;
        firstC[firstDigt(x)]++;
        cnt[x]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] != b[j]) {
                if (a[i] % 10 == firstDigt(b[j])) {
                    ans += (long long) firstC[b[j] % 10];
                    if (b[j] % 10 == firstDigt(b[j])) ans -= cnt[b[j]];
                    if (firstDigt(a[i]) == b[j] % 10) ans -= cnt[a[i]];
                }
            }
        }
    }
    cout << ans;
}
