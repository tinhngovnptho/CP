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

const int MAXN = 5e6+11;

int n;
bool prime[MAXN];

void sieve(int n) {
	memset(prime, -1, sizeof prime);
	FORE(i, 2, sqrt(n)) if (prime[i]) FORE(j, i, n / i) prime[i * j] = 0;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("GOLDBACH");
	cin >> n;
	sieve(n);
	int cnt = 0;
	FORE(i, 2, n / 2) if(prime[i] && prime[n - i]) {
		cnt++;
//		cout << i << " " << n - i << "\n";
	}
	cout << cnt;

	return 0;
}
