/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-16
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#define ssz(s) ((int) (s).size())
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;
typedef unsigned long long uint64;
////////////////////////////////////////

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
	static_assert(D >= 1, "Init Error");
	template <typename... Args>
	vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};

template <typename T>
struct vec<T, 1> : public vector<T> {
	vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};

const int MOD = 1e9 + 7;

int n;
int64 k;

struct Matrix {
	vec<int64, 2> a;
	int r, c;
	Matrix() {
		a.clear();
		r = c = 0;
	}
	Matrix(int _r, int _c) : r(_r), c(_c) {
		a = vec<int64, 2>(r, c, 0);
	}

	Matrix operator * (const Matrix &other) {
		Matrix res(r, other.c);

		assert(c == other.r);

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < other.c; ++j) {
				for (int k = 0; k < c; ++k) {
					res.a[i][j] += 1LL * a[i][k] * other.a[k][j] % MOD;
					res.a[i][j] %= MOD;
				}
			}
		}

		return res;
	}

	Matrix operator ^ (int64 exp) {
		assert(r == c);
		Matrix base = *this;
		Matrix ans(r, c);
		for (int i = 0; i < r; ++i) ans.a[i][i] = 1;

		for (; exp; exp >>= 1LL, base = base * base) if (exp & 1) {
			ans = ans * base;
		}
		return ans;
	}
};

void tinhnop() {
	cin >> n >> k;
	Matrix mat(n, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat.a[i][j];
		}
	}
	Matrix ans = mat ^ k;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res += ans.a[i][j];
			res %= MOD;
		}
	}
	cout << res;
}
////////////////////////////////////////
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("r.inp", "r", stdin);
	freopen("r.out", "w", stdout);
///////////////////////////////////////
	tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
