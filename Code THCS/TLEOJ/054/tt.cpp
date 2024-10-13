#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;
typedef __int128_t int128;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e6 + 11;

int n, q, a[MAXN];
int64 pref[MAXN];

void process(void) {
	cin >> n >> q;
	FORE(i, 1, n) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	int div = 2;
	int64 sum = 0;
	FORE(i, 1, n) sum += a[i];
	FORE(i, 1, q) {
		int l, r; cin >> l >> r;
		if (sum == 0) {
			cout << 0 << "\n";
			continue;
		}
		if (pref[r] - pref[l - 1] == 0) {
			cout << sum << "\n";
			continue;
		}
		FORE(i, l, r) {
			sum = sum - a[i] + a[i] / 2;
			a[i] /= 2;
		}
		FORE(i, l, n) pref[i] = pref[i - 1] + a[i];
		cout << sum << "\n";
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("tt");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
