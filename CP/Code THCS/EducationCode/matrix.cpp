#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, b, a) for (int i = (b); i >= (a); i--)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long

template<class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template<class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template<class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; }

const int MOD = 1e9+7;

struct matrix {
	int x[2][2];
	matrix() {
		memset(x, 0, sizeof x);
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	matrix result;
	FOR(i, 0, 1) {
		FOR(j, 0, 1) {
			FOR(k, 0, 1) {
				result.x[i][j] += 1LL * a.x[i][k] * b.x[k][j] % MOD;
				result.x[i][j] %= MOD;
			}
		}
	}
	return result;
}

matrix Pow(matrix a, long long x) {
	matrix result;
	FOR(i, 0, 1) result.x[i][i] = 1;
	while (x) {
		if (x & 1) {
			result = result * a;
		}
		a = a * a;
		x >>= 1;
	}
	return result;
}

int Fibo(ll n) {
	matrix T;
	T.x[0][0] = T.x[0][1] = T.x[1][0] = 1;

	matrix U;
	U.x[0][0] = 1;
	U.x[1][0] = 1;

	matrix ans = Pow(T, n-1);
	ans = ans * U;
	return ans.x[0][0];
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	int ntests; cin >> ntests;
	while (ntests--) {
		ll x;
		cin >> x;
		cout << Fibo(x) << "\n";
	}
}
