#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

#define MAXN	2000200

int n;
ll a[MAXN];

namespace Sub1 {
	bool check() {
		FOR(i, 1, n) {
			if (abs(a[i]) > 2e6) {
				return true;
			}
		}
		return false;
	}

	bool isPrime(ll x) {
		FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
		return x > 1;
	}

	bool isSpecial(ll x) {
		if (!isPrime(x)) return false;
		int cntOdd = 0, cntEven = 0;
		while (x) {
			if ((x % 10) % 2 == 0) cntEven++;
			else cntOdd++;
			x /= 10;
		}
		return cntEven != cntOdd;
	}

	void solve() {
		int cnt = 0;
		FOR(i, 1, n) {
			if (a[i] > 1) {
				if (isSpecial(a[i])) {
					cnt++;
				}
			}
		}
		cout << cnt;
	}
}

namespace Sub2 {
	bool prime[MAXN];

	void Sieve(int n) {
		memset(prime, -1, sizeof prime);
		FOR(i, 2, sqrt(n)) if (prime[i]) {
			for (int j = i*i; j <= n; j += i) prime[j] = 0;
		}
	}

	bool isSpecial(ll x) {
		if (!prime[x]) return false;
		int cntOdd = 0, cntEven = 0;
		while (x) {
			if ((x % 10) % 2 == 0) cntEven++;
			else cntOdd++;
			x /= 10;
		}
		return cntEven != cntOdd;
	}

	void solve() {
		Sieve(MAXN-1);
		int cnt = 0;
		FOR(i, 1, n) {
			if (a[i] > 1) {
				cnt += isSpecial(a[i]);
//				cout << a[i] << " ";
			}
		}

		cout << cnt;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("sodb.inp", "r", stdin);
	freopen("sodb.out", "w", stdout);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}

	if (Sub1::check()) Sub1::solve();
	else Sub2::solve();

	return 0;
}
