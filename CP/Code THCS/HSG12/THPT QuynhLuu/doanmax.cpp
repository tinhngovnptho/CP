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

const int MAXN = 32000;

int n, a[MAXN];

void process(void) {
	cin >> n;
	REP(i, n) cin >> a[i];
	int cur_last = 0, cur_len = 0, len = 1, last = 0;
	FOR(i, 1, n) {
		if (a[i] < a[last]) {
			if (maximize(cur_len, len)) {
				cur_last = last;
			}
			last = i;
			len = 1;
		} else {
			len++;
			last = i;
		}
	}
	cout << cur_len << "\n";
	FORE(i, cur_last - cur_len + 1, cur_last) cout << a[i] << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
