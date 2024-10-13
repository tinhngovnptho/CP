#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
#define FORA(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long

template <class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template <class T> T abs(const T &a) { return a >= 0 ? a : -a; }

const int MAX_N = 1e5+11, MAX_VAL = 1e7+11;

int a[MAX_N], prefix[MAX_N], T, n;

namespace Sub12 {
	bool isPrime(int x) {
		FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
		return x > 1;
	}
	bool isSPrime(int x) {
		while (x > 0) {
			if (!isPrime(x)) {
				return false;
			}
			x /= 10;
		}
		return true;
	}
	bool isPotentialSprime(int x) {
		if (!isSPrime(x)) return false;
		for (int i = 1; i <= 9; i += 2) {
			if (isPrime(x*10+i)) return true;
		}
		return false;
	}
	void process(void) {
		prefix[0] = 0;
		FOR(i, 1, n) {
			prefix[i] = prefix[i-1] + isPotentialSprime(a[i]);
		}
	}
}

namespace Sub3 {
	bool prime[MAX_VAL];

	void Sieve(int n) {
		memset(prime, 1, sizeof(prime));
		prime[0] = prime[1] = 0;
		FOR(i, 2, sqrt(n)) if (prime[i]) {
			for (int j = i*i; j <= n; j += i) prime[j] = 0;
		}
	}
	bool isSPrime(int x) {
		while (x > 0) {
			if (!prime[x]) return false;
			x /= 10;
		}
		return true;
	}
	bool isPotentialSprime(int x) {
		if (!isSPrime(x)) return false;
		for (int i = 1; i <= 9; i += 2) {
			if (prime[x*10+i]) return true;
		}
		return false;
	}
	void process(void) {
		Sieve(MAX_VAL-1);
		prefix[0] = 0;
		FOR(i, 1, n) {
			prefix[i] = prefix[i-1] + isPotentialSprime(a[i]);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	if (n <= 1000)
		Sub12::process();
	else
		Sub3::process();

	cin >> T;
	while (T--) {
		int u, v;
		cin >> u >> v;
		cout << prefix[v] - prefix[u-1] << "\n";
	}

	return 0;
}
