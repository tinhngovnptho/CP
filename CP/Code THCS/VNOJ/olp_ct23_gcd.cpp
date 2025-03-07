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

long long a, b, m;

struct Matrix {
	long long a[2][2];
	Matrix() {
		memset(a, 0, sizeof a);
	}
};

long long mul(long long a, long long b) {
	a %= m;
	long long ans = 0;
	while(b) {
		if (b & 1) ans = (ans + a % m) % m;
		a = 2 * a % m;
		b /= 2;
	}
	return ans;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix ans;
	FOR(i, 0, 2) FOR(j, 0, 2) FOR(k, 0, 2) {
		ans.a[i][j] += mul(a.a[i][k], b.a[k][j]);
		ans.a[i][j] %= m;
	}
	return ans;
}

Matrix Pow(Matrix a, long long b) {
	Matrix ans;
	/// ans is identity matrix
	ans.a[0][0] = ans.a[1][1] = 1;
	while(b) {
		if (b & 1LL) ans = ans * a;
		a = a * a;
		b /= 2;
	}
	return ans;
}

long long gcd(long long a, long long b) {
	long long r;
	while(b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
	cin >> a >> b >> m;

	long long d = gcd(a, b);
//	cout << d << "\n";
	Matrix factor;
	factor.a[0][0] = factor.a[0][1] = factor.a[1][0] = 1;
	factor = Pow(factor, d-1);
//	FOR(i, 0, 2) FOR(j, 0, 2) cout << factor.a[i][j] << " ";
//	cout << "\n";
	Matrix base;
	base.a[0][0] = 1;

	Matrix ans = factor * base;

	cout << ans.a[0][0];

	return 0;
}
