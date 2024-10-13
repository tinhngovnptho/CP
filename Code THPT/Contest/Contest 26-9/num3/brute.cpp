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

bool check(int x) {
    string s = to_string(x);
    FOR(i, 0, SZ(s) - 1) FOR(j, i + 1, SZ(s) - 1) if ((s[i] + s[j] - '0' - '0') % 3 == 0) return false;
    return true; 
}

void process(void) {    
    int L, R; cin >> L >> R;
    int cnt = 0;
    FOR(i, L, R) if (i % 19 == 0 && check(i)) cnt++;
    cout << cnt << el; 
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while (t--)
    process();

    return 0;
}
