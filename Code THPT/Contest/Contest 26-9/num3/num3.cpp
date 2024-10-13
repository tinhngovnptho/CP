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
#define OFFBIT(i, mask) (mask & ~(MASK(i)))
#define int long long 

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MOD = 1e9 + 7;

string L, R;
int dp[10011][22][15];

int calc(const string &x, int id, int mod, int mask, bool tight) {
    if (id < 0) {
        return (mod == 0);
    }
    
    if (!tight && ~dp[id][mod][mask]) return dp[id][mod][mask]; 

    int res = 0;
    int d = x[id] - '0';
    int maxDigt = tight ? d : 9;
    FOR(i, 0, maxDigt) {
        int k = (3 - i % 3) % 3;
        if ((mask >> k) & 1) continue;
        int new_mask = ONBIT(i % 3, mask);
        if (!mask && !i) new_mask = 0;
        bool new_tight = tight && (i == maxDigt);
        res += calc(x, id - 1, (mod * 10 + i) % 19, new_mask, new_tight);
        res %= MOD; 
    }
    
    if (!tight) dp[id][mod][mask] = res;
    return res;
}

string dec(string s) {
    string a;
    FOR(i, 0, SZ(s) - 1) a.push_back('0');
    a[SZ(s) - 1] = '1';
    string res = "";
    // cout << a << " " << s << el; 
    int carry = 0, d;
    FORD(i, SZ(s) - 1, 0) {
        d = (s[i] - '0') - (a[i] - '0') - carry;
        if (d < 0) {
            d += 10;
            carry = 1;
        } else carry = 0;
        res = char(d + '0') + res;
        // cout << res << el;
    }
    while (res.size() > 1 && res[0] == '0') res.erase(res.begin());
    return res; 
}

void process(void) {
    cin >> L >> R;
    L = dec(L);
    reverse(ALL(L));
    reverse(ALL(R));
    cout << (calc(R, SZ(R) - 1, 0, 0, true) - calc(L, SZ(L) - 1, 0, 0, true) + MOD) % MOD << el;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);    
    int t; cin >> t; while (t--)
    process();

    return 0;
}
