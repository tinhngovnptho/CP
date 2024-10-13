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

struct car
{
	int a, b, idx;
};

car v[100000+11];
int n;

bool cmp(const car &a, const car &b)
{
	return 1LL * a.a * b.b > 1LL * b.a * a.b;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	file("");

	cin >> n;
	ForE(i, 1, n) cin >> v[i].a;
	ForE(i, 1, n)
	{
		cin >> v[i].b;
		v[i].idx = i;
	}
	sort(v+1, v+n+1, cmp);
//	ForE(i, 1, n) cerr << v[i].a << " " << v[i].b << "\n";
	ll day = 0, ans = 0;
	ForE(i, 1, n)
	{
		day += v[i].b;
		ans += v[i].a * day;
	}
	cout << ans << endl;
	ForE(i, 1, n) cout << v[i].idx << " ";
}

/**-----------------------------------------
-------------Author: tinhnopro -------------
-----------While(!Die) Code(); <3 ----------
---------//--------NVT---------//-----------
-----------------------------------------**/
