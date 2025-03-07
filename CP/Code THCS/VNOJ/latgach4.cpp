// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MOD = 111539786;

struct Matrix {
	vector <vector<int> > a;
	int r, c;
    Matrix(int r = 0, int c = 0): r(r), c(c), a(r, vector<int>(c, 0)) {}
	Matrix (vector<vector<int> > a): r(a.size()), c(a[0].size()), a(a) {}
	Matrix operator * (const Matrix &other) const {
		Matrix res(r, other.c);
		REP(i, r) REP(j, other.c) REP(k, c) {
			res.a[i][j] += 1LL * a[i][k] * other.a[k][j] % MOD;
			res.a[i][j] %= MOD;
		}
		return res;
	}
	Matrix pow(long long n) const {
		Matrix res(r, c), a = *this;
		REP(i, r) res.a[i][i] = 1;
		for (; n; n >>= 1, a = a * a) if (n & 1) res = res * a;
		return res;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	int tests; cin >> tests;
	Matrix factor ({
		{1, 1},
		{1, 0}
	});
	while (tests--) {
		long long n;
		cin >> n;
		Matrix tmp = factor.pow(n - 1);
		cout << (tmp.a[0][0] + tmp.a[0][1]) % MOD << "\n";
	}

	return 0;
}
