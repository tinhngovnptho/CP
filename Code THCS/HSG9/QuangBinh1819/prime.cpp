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

const int MAX = 1e6 + 11;

int n, cnt = 0, a[10];
bool used[10], prime[MAX];

bool isPrime(int x) {
	if (x <= 3) return x > 1;
	if (x % 2 == 0 || x % 3 == 0) return false;
	for (int i = 5; i <= sqrt(x); i += 6) if (x % i == 0 || x % (i + 2) == 0) return false;
	return true;
}

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	prime[0] = prime[1] = 0;
	FORE(i, 2, sqrt(n)) if (prime[i]) FORE(j, i, n / i) prime[i * j] = 0;
}

void backtrack(int pos, int val) {
	if (pos > n) return ;
	bool check = false;
	if (pos > 6) check = isPrime(val);
	else check = prime[val];
	if (check) cnt++;
//	cout << val << "\n";
	REP(i, n) if (!used[i]) {
		used[i] = true;
		int new_val = val * 10 + a[i];
		backtrack(pos + 1, new_val);
		used[i] = false;
	}
}

void process(void) {
	cin >> n;
	sieve(MAX-1);
	REP(i, n) cin >> a[i];
	backtrack(0, 0);
	cout << cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
