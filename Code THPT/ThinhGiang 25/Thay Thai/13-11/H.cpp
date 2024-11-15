/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-13
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#define ALL(v) (v).begin(), (v).end()
#define ssize(s) (int) (s).size()

#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template <typename A, typename B> bool minimize(A &a, B b)  { return a > b ? a = b, true : false; }
template <typename A, typename B> bool maximize(A &a, B b)  { return a < b ? a = b, true : false; }
//} end of template

const int MOD = (int) 1e9 + 7;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	file("H");
//__________________________________
	int n, m, L, R;
	cin >> n >> m >> L >> R;

	vector<int> f(m + 2, 0), used(m + 2, 0);

	auto Pow = [&] (int a, int b) -> int {
		if (used[a]) return used[a];
		int res = 1, tmp = a;
		for (; b; b >>= 1, a = 1LL * a * a % MOD)
			if (b & 1) res = 1LL * res * a % MOD;
		used[tmp] = res;
		return res;
	};

	auto add = [&] (int &a, int b) -> void {
		a += b;
		if (a >= MOD) a -= MOD;
	};

	auto sub = [&] (int &a, int b) -> void {
		a -= b;
		if (a < 0) a += MOD;
	};

	int ans = 0;

	for (int d = m; d >= 1; --d) {
		f[d] = Pow(m / d, n);
		for (int k = 2; k * d <= m; ++k) {
			sub(f[d], f[k * d]);
		}
	}

	for (int i = L; i <= R; ++i) add(ans, f[i]);

	cout << ans;
}
