#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e5 + 11;

int n, a[MAXN], maxGcd[MAXN];
pair<int, int> usedDiv[MAXN];

int gcd(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

namespace Sub1 {
	void solve() {
		int ans = 0;
		FORE(i, 1, n) FORE(j, i + 1, n) FORE(k, j + 1, n) FORE(t, k + 1, n) {
			maximize(ans, gcd(a[i], a[j]) + gcd(a[k], a[t]));
		}
		cout << ans;
	}
};

namespace Sub2 {
	void solve() {
		int ans = 0;
		FORDE(i, n - 1, 1) {
			maxGcd[i] = maxGcd[i + 1];
			FORE(j, i + 1, n) {
				maximize(maxGcd[i], gcd(a[i], a[j]));
				if (maxGcd[j + 1]) maximize(ans, gcd(a[i], a[j]) + maxGcd[j + 1]);
			}
		}
		cout << ans;
	}
};

namespace Sub3 {
	void solve() {
		int ans = 0;
		FORDE(i, n, 1) {
			maxGcd[i] = maxGcd[i + 1];
			FORE(j, 1, sqrt(a[i])) if (a[i] % j == 0) {
				int t = j;
				if (usedDiv[t].fi) {
					if (maxGcd[usedDiv[t].se + 1]) maximize(ans, t + maxGcd[usedDiv[t].se + 1]);
					maximize(maxGcd[i], t);
				}
				t = a[i] / j;
				if (usedDiv[t].fi) {
					if (maxGcd[usedDiv[t].se + 1]) maximize(ans, t + maxGcd[usedDiv[t].se + 1]);
					maximize(maxGcd[i], t);
				}
				usedDiv[j].fi = usedDiv[a[i] / j].fi = 1;
				usedDiv[j].se = usedDiv[a[i] / j].se = i;
			}
		}
		cout << ans;
	}
}

void process(void) {
	cin >> n;
	FORE(i, 1, n) cin >> a[i];
	if (n <= 50) return void(Sub1::solve());
	if (n <= 1e3) return void(Sub2::solve());
	Sub3::solve();
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("cau4");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
