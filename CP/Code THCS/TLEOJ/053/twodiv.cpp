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

const int MAX = 2e6 + 11;

int n, a[MAX];
bool prime[MAX];
vector<int> list_prime;

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	FORE(i, 2, sqrt(n)) if (prime[i]) FORE(j, i, n / i) prime[i * j] = 0;
	FORE(i, 2, n) if (prime[i])list_prime.push_back(i);
}

void process(void) {
	cin >> n;
	FORE(i, 1, n) cin >> a[i];
	sieve(MAX - 1);
	FORE(i, 1, n) {
		int idx = upper_bound(ALL(list_prime), a[i]) - list_prime.begin() - 1;
		a[i] = list_prime[idx];
		cout << a[i] << " ";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("twodiv");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
