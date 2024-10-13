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

const int MOD = 1e9 + 7;
const int MAX = 5e5 + 11;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int n, k, l[MAX];

void process(void) {
	cin >> n >> k;
	FORE(i, 1, k) cin >> l[i];
	if (k == 2) {
		int max_l = max(l[1], l[2]);
		int ans = n - max_l + 1;
		FORE(i, 1, n - max_l + 1) {
			add(ans, (min(i + l[1] - 1, max(n - l[2] + 1, i)) - i) * 2);
		}
		cout << ans;
		return ;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("tapdt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
