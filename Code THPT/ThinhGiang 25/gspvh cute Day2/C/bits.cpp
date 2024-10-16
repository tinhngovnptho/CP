#include<bits/stdc++.h>

#define name "bits"
#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()
#define szv(v) int((v).size())
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

using namespace std;

using i64 = long long;
using db = long double;
using vi = vector<int>;

template<class T> using pairD = pair<T, T>;

template<class T> using vector2d = vector<vector<T>>;

template<class X, class Y> bool maximize(X &a, Y b) {
    return a < b ? a = b, 1 : 0;
}

template<class X, class Y> bool minimize(X &a, Y b) {
    return a > b ? a = b, 1 : 0;
}

template<class X, class Y> void modmize(X &a, const Y& mod) {
    if (a >= mod) a -= mod;
    // a %= mod;
}

template<class T> T Abs(const T &x) {
    return x < 0 ? -x : x;
}
//____________________________________________________________________

// const int MAXN = 5e5 + 11; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7;
// const int INF = 1e9 + 11; // const ll INFF = 1e18 + 11;

string s1, s2;

void tinhnopro(void) {
    cin >> s1 >> s2;
    int n = szv(s1);
    
    int cnt0, cnt1, cnt_s0, cnt_s1;

    cnt0 = cnt1 = cnt_s0 = cnt_s1 = 0;

    FOR(i, 0, n - 1) {
        if (s1[i] == '1' && s2[i] == '0') cnt1++;
        else if (s1[i] == '0' && s2[i] == '1') cnt0++;
        else if (s1[i] == '?' && s2[i] == '0') cnt_s0++;
        else if (s1[i] == '?' && s2[i] == '1') cnt_s1++;
    }

    int res = min(cnt0, cnt1);
    int ans = res; 
    cnt0 -= res; 
    cnt1 -= res; 
    ans += cnt0;
    res = min(cnt1, cnt_s1);

    ans += 2 * res;

    cnt1 -= res; 
    cnt_s1 -= res; 

    if (cnt1 > 0) {
        cout << -1;
        return ;
    }

    ans += cnt_s1 + cnt_s0;

    cout << ans;
    
}

//____________________________________________________________________

int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    // int t; cin >> t; while (t--)
    tinhnopro();

    cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
