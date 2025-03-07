#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= (b); ++i)
#define FORA(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int) (x).size()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) {
	return a < b ? a = b, 1 : 0;
}

template <class X, class Y> bool minimize(X &a, const Y &b) {
	return a > b ? a = b, 1 : 0;
}

int gcd(int a, int b) {
	int r;
	while(b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void solve(void) {
	int a, b; cin >> a >> b;
	if (gcd(a, b) != 1) return void(cout << 0 << "\n");
	int ans = (a - b % a);
	FOR(i, 2, sqrt(a)) if (a % i == 0) {
		minimize(ans, i - b % i);
		int d = a / i;
		minimize(ans, d - b % d);
	}

	cout << ans << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	int t; cin >> t; while (t--) {
		solve();
	}

	return 0;
}
