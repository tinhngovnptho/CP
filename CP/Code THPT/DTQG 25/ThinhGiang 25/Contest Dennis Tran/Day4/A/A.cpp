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

int a, b;

int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void process(void) {
    cin >> a >> b;
    int g = gcd(a, b);
    ll x = 1LL * a * b;
    x /= g;
    x /= g;
    ll s = sqrt(x);
    ll tmp = x;
    vector<ll> tinhnopro;
    FOR(i, 2, sqrt(x)) {
        if (x % i == 0) {
            while(x % i == 0) {
                x /= i;
                tinhnopro.push_back(i);
            }
        }
    }
    tinhnopro.push_back(x);
    ll res = 1; 
    FOR(mask, 1, MASK(tinhnopro.size()) - 1) {
        ll c = 1;
        FOR(i, 0, SZ(tinhnopro) - 1) if ((mask >> i) & 1) {
            c = c * tinhnopro[i];
            if (c > s) break;
        }
        if (c <= s) maximize(res, c);
    }
    cout << 1LL * g * res << " " << 1LL * g * tmp / res; 
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define Task "A"
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    return 0;
}
