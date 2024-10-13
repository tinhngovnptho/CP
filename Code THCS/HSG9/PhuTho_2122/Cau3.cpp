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
const int mxN  = 1e6 + 11;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long cnt[5];
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cnt[x % 5]++;
    }
    long long ans = cnt[0]*(cnt[0]-1)*(cnt[0]-2)/6;
    ans += cnt[0]*cnt[1]*cnt[4];
    ans += cnt[0]*cnt[2]*cnt[3];
    ans += cnt[1]*cnt[2]*(cnt[2]-1)/2;
    ans += cnt[1]*(cnt[1]-1)*cnt[3]/2;
    ans += cnt[2]*cnt[4]*(cnt[4]-1)/2;
    ans += cnt[3]*(cnt[3]-1)*cnt[4]/2;
    cout << ans;
}
