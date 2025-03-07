/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-24
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#if __cplusplus < 202002L
template <class T> int ssize(const T &a) { return a.size(); }
#endif // __cplusplus

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

using int64 = long long;
using ii = pair<int64_t, int64_t>;

const int maxN = 3e6 + 11;

int n, k;
char s[maxN];

struct Poly_hash {
	static const int64 base1 = 311, base2 = 317;
	static const int64 mod = (int64) 1e9 + 7;

	int64 pref[2][maxN], suff[2][maxN], pw[2][maxN];
	int sz;

	Poly_hash() {
		sz = 0;
	}

	void init(const char *s, int _sz) {
		sz = _sz;

		pw[0][0] = pw[0][1] = 1;

		for (int i = 1; i <= sz; ++i) {
			pw[0][i] = pw[0][i - 1] * base1 % mod;
			pw[1][i] = pw[1][i - 1] * base2 % mod;
			pref[0][i] = (pref[0][i - 1] * base1 % mod + s[i] + 1) % mod;
			pref[1][i] = (pref[1][i - 1] * base2 % mod + s[i] + 1) % mod;
			suff[0][i] = (suff[0][i - 1] * base1 % mod + s[sz - i + 1] + 1) % mod;
			suff[1][i] = (suff[1][i - 1] * base2 % mod + s[sz - i + 1] + 1) % mod;
		}
	}

	ii get(int l, int r) const {
		return make_pair((pref[0][r] - pref[0][l - 1] * pw[0][r - l + 1] % mod + mod * mod) % mod,
										(pref[1][r] - pref[1][l - 1] * pw[1][r - l + 1] % mod + mod * mod) % mod);
	}

	ii getrev(int l, int r) const {
		return make_pair((suff[0][r] - suff[0][l - 1] * pw[0][r - l + 1] % mod + mod * mod) % mod,
										(suff[1][r] - suff[1][l - 1] * pw[1][r - l + 1] % mod + mod * mod) % mod);
	}

	bool isPalin(int l, int r) {
		return get(l, r) == getrev(l, r);
	}
} Hash;

namespace Sub12 {

	bool check() {
		return n * k <= 2000000;
	}

	bool checkLen(const int &len, const int &sz) {
		for (int i = 1; i <= sz - len + 1; ++i) {
			if (Hash.isPalin(i, i + len - 1)) return true;
		}
		return false;
	}

	void solve() {
		for (int i = n + 1, id; i <= k * n; ++i) {
			id = i % n + (i % n == 0 ? n : 0);
			s[i] = s[id];
		}

		int sz = k * n;
		Hash.init(s, sz);
		int ans = 0;

		int l = 2, r = sz - (sz % 2);
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (mid & 1) mid++;
			if (checkLen(mid, sz)) l = mid;
			else r = mid - 2;
		}

		maximize(ans, l);

		l = 1, r = sz - (sz % 2 == 0);
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (mid % 2 == 0) mid++;
			if (checkLen(mid, sz)) l = mid;
			else r = mid - 2;
		}

		maximize(ans, l);

		cout << ans;
	}
}

namespace SubLao {
	void solve() {
		k = 2;
		Sub12::solve();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("palin.inp", "r", stdin);
	freopen("palin.out", "w", stdout);


	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	if (Sub12::check()) return Sub12::solve(), 0;
	SubLao::solve();
}
