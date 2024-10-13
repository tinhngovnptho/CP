// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define all(v) (v).begin(), (v).end()
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "csxor"

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

const int MAXN = 1e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int n;
char a[MAXN];
int cnt1[MAXN], b[MAXN];

namespace Sub1 {
    string xorStr(string s) {
        string res;
        res.resize(n);
        FORD(i, n, 1) {
            if (s.back() == 'x') break; 
            int c = a[i] - '0';
            int d = s.back() - '0';
            d ^= c;
            res[i - 1] = char(d + '0');
            s.pop_back();
            if (s.empty()) {
                FOR(j, 1, i - 1) res[j - 1] = a[j];
                break;
            }
        }

        return res; 
    }
    void solve(void) {
        int first_0 = -1;
        FOR(i, 1, n) if (a[i] == '0') {
            first_0 = i;
            break;
        }
        if (first_0 == -1) {
            FOR(i, 1, n - 1) cout << 1;
            cout << 0 << el;
            return ;
        }
        int Sz = n - first_0 + 1;
        int res = -1, pos = -1;
        string ans;
        FOR(i, 1, n) ans.push_back('0');
        FOR(sz, 1, Sz) {
            string s2 = "";
            FOR(j, 1, sz) s2.push_back(a[j]);
            maximize(ans, xorStr(s2));
            int idx = 0;
            FOR(j, sz + 1, n) {
                s2[idx] = 'x';
                ++idx;
                s2.push_back(a[j]);
                maximize(ans, xorStr(s2));  
            }
        }
        cout << ans;
    }
}

namespace Sub2 {
    string xorStr(string s) {
        string res;
        res.resize(n);
        FORD(i, n, 1) {
            int c = a[i] - '0';
            int d = s.back() - '0';
            d ^= c;
            res[i - 1] = char(d + '0');
            s.pop_back();
            if (s.empty()) {
                FOR(j, 1, i - 1) res[j - 1] = a[j];
                break;
            }
        }

        return res; 
    }
    void solve(void) {
        int first_0 = -1;
        FOR(i, 1, n) if (a[i] == '0') {
            first_0 = i;
            break;
        }
        if (first_0 == -1) {
            FOR(i, 1, n - 1) cout << 1;
            cout << 0 << el;
            return ;
        }
        int sz = n - first_0 + 1;
        FOR(i, 1, n) cnt1[i] = cnt1[i - 1] + (a[i] == '1');
        int res = -1, pos = -1;
        string ans;
        FOR(i, 1, n) ans.push_back('0');
        string s2;
        FOR(j, 1, sz) s2.push_back(a[j]);
        maximize(ans, xorStr(s2));
        FOR(j, sz + 1, n) {
            s2.erase(s2.begin());
            s2.push_back(a[j]);
            maximize(ans, xorStr(s2));  
        }
        cout << ans;
    }
}

namespace Brute {
    void solve(void) {
        int first_0 = -1;
        FOR(i, 1, n) if (a[i] == '0') {
            first_0 = i;
            break;
        }
        if (first_0 == -1) {
            FOR(i, 1, n - 1) cout << 1;
            cout << 0 << el;
            return ;
        }
        int sz = n - first_0 + 1;
        FOR(i, 1, n) cnt1[i] = cnt1[i - 1] + (a[i] == '1');
        int res = -1, pos = -1;
        FOR(j, sz, n) {
            int i = j - sz + 1;
            if (maximize(res, cnt1[j] - cnt1[i - 1])) {
                pos = i;
            }
        }
        FOR(i, 1, n) b[i] = a[i] - '0';
        int idx = n;
        FORD(j, pos + sz - 1, pos) {
            b[idx] ^= (a[j] - '0');
            idx--;
        }
        FOR(i, 1, n) cout << b[i];
        cout << el;
    }
}
void solve(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];   
    if (n <= 500) return void(Sub1::solve());
    if (n <= 3000) return void(Sub2::solve());
    return void(Brute::solve());
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    int t; cin >> t; while (t--) {
        solve();
    }

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
