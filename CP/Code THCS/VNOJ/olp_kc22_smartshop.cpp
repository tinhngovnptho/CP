#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define vt vector
#define pub push_back
#define all(s) (s).begin(), (s).end()
#define sz(s) (int)(s).size()
#define sqr(x) (x) * (x)
#define FORC(i, a, b, s) for (__typeof(a) i=(a); (s)>0 ? i<=(b) : i>=(b); i+=(s))
#define FOR(i, a, b) FORC(i, a, b, 1)
#define FORD(i, a, b) FORC(i, a, b, -1)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define tinhnopro signed main

template<class T> bool umin(T& a, const T& b)
{
    return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b)
{
    return a < b ? a = b, 1 : 0;
}

const ll oo  = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN  = 1e6 + 11;

int n, m, x;
vt<int> v;
set<int> goodNum;

void add(int base)
{
        int res = base;
        while (res <= INF)
        {
                goodNum.insert(res);
                res *= base;
        }
}

void init()
{
        goodNum.insert(1);
        add(2); add(3); add(5);
}

tinhnopro()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
//        file("KEK");
        init();
        cin >> n >> m;
        FOR(i, 1, n)
        {
                cin >> x;
                if (goodNum.find(x) != goodNum.end()) v.pub(x);
        }
        sort(all(v));
//        FOR(i, 0, sz(v)-1) cout << v[i] << " ";
        while (m--)
        {
                int L, R;
                cin >> L >> R;
                int l = lower_bound(all(v), L) - v.begin();
                int r = upper_bound(all(v), R) - v.begin() - 1;
                cout << r - l + 1 << "\n";
        }
}
