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

int numVote[5001];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    file("VOTE");

    int n;
    char x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            numVote[j] += (x == 'X');
        }
    }
    int maxVote = *max_element(numVote + 1, numVote + n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (numVote[i] == maxVote) ans.push_back(i);
    }
    cout << (int) ans.size() << " " << maxVote << "\n";
    for (int i = 0; i < (int) ans.size(); ++i) cout << ans[i] << " ";
}
