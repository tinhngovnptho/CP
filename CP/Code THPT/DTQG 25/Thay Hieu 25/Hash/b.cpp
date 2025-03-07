/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-15
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef tinhnop_local
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // tinhnop_local

#define ALL(v)	(v).begin(), (v).end()
#define ssize(s) ((int) (s).size())

template <typename A, typename B>
bool minimize(A &a, B b) {
	return a > b ? a = b, true : false;
}

template <typename A, typename B>
bool maximize(A &a, B b) {
	return a < b ? a = b, true : false;
}

void logtime() {
	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}

void tinhnop();

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0); atexit(logtime);
#ifdef tinhnop_local
	freopen("b.inp", "r", stdin);
	freopen("b.out", "w", stdout);
#endif // tinhnop_local
	tinhnop();
}
//}

struct Poly_hash {
	static const int64_t base = 311;
	static const int64_t mod = (int64_t) 1e9 + 7;

	vector<int64_t> pref, suff, pw;
	int sz;

	Poly_hash() {
		pref.clear();
		suff.clear();
		pw.clear();
		sz = 0;
	}

	Poly_hash(const string &s, int _sz) {
		int sz = _sz;

		pref.resize(sz + 2);
		suff.resize(sz + 2);
		pw.resize(sz + 2);

		pw[0] = 1;

		for (int i = 1; i <= sz; ++i) {
			pw[i] = pw[i - 1] * base % mod;
			pref[i] = (pref[i - 1] * base % mod + s[i] + 1) % mod;
			suff[i] = (suff[i - 1] * base % mod + s[sz - i + 1] + 1) % mod;
		}
	}

	int64_t get(int l, int r) const {
		return (pref[r] - pref[l - 1] * pw[r - l + 1] % mod + mod * mod) % mod;
	}

	int64_t getrev(int l, int r) const {
		return (suff[sz - l + 1] - suff[sz - r] * pw[r - l + 1] % mod + mod * mod) % mod;
	}
};

void tinhnop() {
	string s;
	cin >> s;
	int n = ssize(s);
	s = " " + s;
	Poly_hash Hash(s, n);


}
