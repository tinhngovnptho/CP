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

const int MAXN = 1e6 + 11;

int n;
long long k, pref[MAXN], d[MAXN];

void process(void) {
	cin >> n >> k;
	FORE(i, 1, n) {
		int x; cin >> x;
		pref[i] = pref[i - 1] + x;
		d[i] = pref[i] - 1LL * i * k;
	}

	int ans = 0;

	unordered_map<long long, int> pos;

	pos[d[0]] = 0;

	FORE(i, 1, n) {
		if (pos.find(d[i]) != pos.end()) {
			maximize(ans, i - pos[d[i]]);
		} else {
			pos[d[i]] = i;
		}
	}
	cout << ans;

}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("tbc");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
