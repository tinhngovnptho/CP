// author : nhatanh_k7
#include <bits/stdc++.h>


#ifdef nhatanh_k7_local
	#include "D:\Code\debug\debug.h"
#else
	#define debug(...) 0
#endif


using namespace std;


#define file(name)  if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout); }
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second




template <class X, class Y> bool maximize(X &a, const Y &b){if(a < b) return a = b, true;return false;}
template <class X, class Y> bool minimize(X &a, const Y &b){if(a > b) return a = b, true;return false;}





ll n, k;
ll a[400005];
ll f[400005][2];
void process(){
	cin >> n >> k;
	for (int i = 1;i <= n;++i){
		cin >> a[i];
		 a[i] = a[i - 1] + a[i];
			f[i][0] = f[i][1] = -1e18;
	}
	for (int i = n + 1;i <= n + k; ++i){
		a[i] = 0;
		 a[i] = a[i - 1] + a[i];
		f[i][0] = f[i][1] = -1e18;
	}
	f[0][0] = 0;
	f[0][1] = -1e18;
	ll res = -1e18;
	for (int i = 1;i <= n + k;++i){
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		f[i][1] = max(f[i][1], f[i - 1][1] + a[i] - a[i - 1]);
		if (i > k) f[i][1] = max(f[i][1], f[max(0ll, i - 2 * k - 1)][0] +
			a[i] - a[max(0ll, i - 2 * k - 1)]);
			res = max(res, f[i][1]);
	}
	cout << res << endl;
}






int main()
{
		ios_base::sync_with_stdio(false); cin.tie(nullptr);
		file("bowling")

		process();




		cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
	 return 0;
}
