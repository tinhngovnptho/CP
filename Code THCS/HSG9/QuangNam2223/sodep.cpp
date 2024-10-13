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

vector<long long> v;

bool isPrime(long long x) {
	FORE(i, 2, sqrt(x)) if (x % i == 0) return false;
	return x > 1;
}

void Sprime(long long x) {
	if (x > 1e15) return ;
	v.push_back(x);
	for (int i = 1; i <= 9; i += 2) {
		if (isPrime(x * 10 + i)) {
			Sprime(x * 10 + i);
		}
	}
}

void process(void) {
	Sprime(2); Sprime(3); Sprime(5); Sprime(7);
	sort(ALL(v));
	int n; cin >> n;
	bool printed = false;
	REP(i, n) {
		long long x; cin >> x;
		if (binary_search(ALL(v), x)) {
			cout << x << "\n";
			printed = true;
		}
	}
	if (!printed) cout << 0;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
