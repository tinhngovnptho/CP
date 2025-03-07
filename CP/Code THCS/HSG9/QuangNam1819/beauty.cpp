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
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MAX = 1e5 + 11;

vector<int> v;
bool prime[1001];

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	prime[0] = prime[1] = 0;
	FOR(i, 2, sqrt(n)) if (prime[i]) FOR(j, i, n / i) prime[i * j] = 0;
}

bool isBeauty(long long x) {
	int res = 0;
	while (x) {
		res += (x % 10) * (x % 10);
		x /= 10;
	}
	return prime[res];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("beauty");
	sieve(1000);
	long long i = 11;
	while (v.size() < MAX) {
		if (isBeauty(i)) v.push_back(i);
		i++;
	}

	int n;
	while (cin >> n) cout << v[--n] << "\n";

	return 0;
}

