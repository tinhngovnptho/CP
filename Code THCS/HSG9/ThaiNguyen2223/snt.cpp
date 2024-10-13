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

const int MAXN = 1e6 + 11;

bool prime[MAXN];
vector<int> list_prime;

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	FORE(i, 2, sqrt(n)) if (prime[i]) FORE(j, i, n / i) prime[i * j] = 0;
	FORE(i, 2, n) if (prime[i]) list_prime.push_back(i);
}

string to_str(int x) {
	string res;
	while (x) {
		res = char(x % 10 + '0') + res;
		x /= 10;
	}
	return res;
}

bool isPrime(long long x) {
	if (x == 2 || x == 3) return 1;
	if (x % 2 == 0 || x % 3 == 0) return 0;
	for (int i = 5; i <= sqrt(x); i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0;
	return x > 1;
}

bool check(int x, int y) {
	string s = to_str(x) + to_str(y);
	long long d = atoll(s.c_str());
	return isPrime(d);
}

void process(void) {
	int k; cin >> k;
	sieve(MAXN - 1);
	REP(i, sz(list_prime)) {
		if (check(list_prime[i], list_prime[i + 1])) {
			k--;
			if (!k) {
				cout << list_prime[i] << list_prime[i + 1];
				break;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();
	return 0;
}
