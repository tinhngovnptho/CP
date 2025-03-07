#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MOD = 20232024;

int64 Mul(int64 a, int64 b) {
	b %= MOD;
	int64 c = a * b;
	c %= MOD;
	return c;
}

int64 Pow(int64 a, int64 b) {
	int64 res = 1;
	for (; b; b /= 2, a = Mul(a, a))
		if (b & 1LL) res = Mul(res, a);
	return res;
}

int64 n, t;
vector<int64> A;

void process(void) {
	cin >> n;
	t = n;
	FORE(i, 2, sqrt(n)) if (n % i == 0) {
		A.push_back(i);
		while (n % i == 0) n /= i;
	}
	if (n > 1 && n != t) A.push_back(n);
	if (A.size() == 0) {
		cout << 1;
		return ;
	}
	int64 res = 1;
	REP(i, sz(A)) res = Mul(res, Pow(3, A[i]) + A[i]);
	cout << res;
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("cau3");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
