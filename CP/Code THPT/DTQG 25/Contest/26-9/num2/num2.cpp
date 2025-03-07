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
#define int long long 

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MOD = 1e9 + 7;
const int MAXN = 1e4 + 11;
const int maxD = 20;

string L, R;

int dp[MAXN][maxD][maxD][2];
int n;
int a[10011];

int calc(int id, int last_digt, int mod, bool low) {

    if (id < 0) return mod == 0;

    if (~dp[id][last_digt][mod][low]) return dp[id][last_digt][mod][low];

    int maxDigt = (low ? 9 : a[id]);
    int res = 0;

    FOR(i, 0, maxDigt) {
        if (i == last_digt) continue;
        int new_last = i;
        if (i == 0 && last_digt == 10) new_last = 10;
        res += calc(id - 1, new_last, (mod * 10 + i) % 17, (low || i < maxDigt));
        res %= MOD;
    }
    return dp[id][last_digt][mod][low] = res; 
}

int solve(string s) {
    n = 0;
    FORD(i, SZ(s) - 1, 0) a[n++] = s[i] - '0';

    return calc(n - 1, 10, 0, 0); 
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

    memset(dp, -1, sizeof dp);

    cout << (solve(R) - solve(dec(L)) + MOD) % MOD;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "num2"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
