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

long long n;

long long count0(long long x) {
	long long res = 5;
	long long cnt = 0;
	while (res <= x) {
		cnt += x / res;
		res = 1LL * res * 5;
	}
	return cnt;
}

void process(void) {
	cin >> n;
	long long L = n, R = 5 * n, res = 0;
	while (L <= R) {
		long long mid = (L + R) >> 1;
		if (count0(mid) >= n) {
			res = mid;
			R = mid - 1;
		} else L = mid + 1;
	}

	cout << res << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("timso");
	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
