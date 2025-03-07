#include<bits/stdc++.h>

// Author: Tinhnopro (a.k.a NVT)

using namespace std;

#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define ld long double
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define ONBIT(i, mask) (mask | MASK(i))
#define OFFBIT(i, mask) mask & ~(MASK(i))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

int k, n;
string a[45];
vector<string> d1[25], d2[25];

string bor(string x, string y) {
    string d;
    FOR(i, 0, x.size() - 1) {
        int c = x[i] + y[i] - '0' - '0';
        c %= 10;
        d.push_back(char(c + '0'));
    }
    return d;
}

void process(void) {
    cin >> n >> k;   
    int mxsz = -1;
    FOR(i, 1, n) {
        cin >> a[i];
        maximize(mxsz, SZ(a[i]));
    }
    FOR(i, 1, n) {
        string &s = a[i];
        while (SZ(s) < mxsz) s = "0" + s;
    }
    
    vector<string> set1, set2;
    FOR(i, 1, n / 2) set1.push_back(a[i]);
    FOR(i, n / 2 + 1, n) set2.push_back(a[i]);
    
    FOR(mask, 0, MASK(SZ(set1)) - 1) {
        int cnt_bit = __builtin_popcount(mask);
        string res;
        FOR(i, 1, mxsz) res.push_back('0');
        FOR(i, 0, SZ(set1) - 1) if ((mask >> i) & 1) {
            res = bor(res, set1[i]);
        }
        d1[cnt_bit].push_back(res);
    } 

    FOR(mask, 0, MASK(SZ(set2)) - 1) {
        int cnt_bit = __builtin_popcount(mask);
        string res;
        FOR(i, 1, mxsz) res.push_back('0');
        FOR(i, 0, SZ(set2) - 1) if ((mask >> i) & 1) {
            res = bor(res, set2[i]);
        }
        d2[cnt_bit].push_back(res);
    } 

    string ans;
    FOR(i, 1, mxsz) {
        ans.push_back('0');
    }

    FOR(c, 1, k - 1) {
        for (string &x : d1[c]) for (string &y : d2[k - c]) {
            maximize(ans, bor(x, y));
        }
    }
    cout << ans;

}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "bor"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
