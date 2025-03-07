#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sqr(x) (ll) (x) * (x)
#define ALL(s) (s).begin(), (s).end()
#define SZ(s) (int)(s).size()
#define For(i, a, b) for (__typeof(a) i = (a); i < (b); ++i)
#define ForE(i, a, b) For(i, a, b+1)
#define ForD(i, b, a) for (__typeof(b) i = (b); i >= (a); --i)
#define file(NAME) if (fopen(NAME".inp", "r")) freopen(NAME".inp", "r", stdin), freopen(NAME".out", "w", stdout);

template <class T> bool umin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template <class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int mxN = 1e5+11;

ll a[mxN], pre[mxN], minL[mxN], minR[mxN];
int n, m;

signed main(void) {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        file("");
        cin >> n;
        ForE(i, 1, n) {
                cin >> a[i];
        }
        pre[0] = 0;
        ForE(i, 1, n) {
                pre[i] = pre[i-1] + a[i];
        }
        minR[n] = pre[n]; minR[0] = 0;
        ForD(i, n-1, 1) {
                minR[i] = min(pre[i], minR[i+1]);
        }
        minL[1] = pre[1]; minL[0] = 0;
        ForE(i, 2, n) {
                minL[i] = min(pre[i], minL[i-1]);
        }
        int cnt = 0;
        ForE(i, 1, n) {
                if ((a[i] > 0) && (minR[i] - pre[i-1] > 0) && (minR[n] - pre[i-1] + minL[i-1] > 0)) cnt++;
        }
        cout << cnt;
}

/**-----------------------------------------
-------------Author: tinhnopro -------------
-----------While(!Die) Code(); <3 ----------
---------//--------NVT---------//-----------
-----------------------------------------**/
