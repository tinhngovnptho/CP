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

const int MAXN = 1e6 + 11;

int n;
char a[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("bai2");
	cin >> n;
	REP(i, n) cin >> a[i];

	int h = 0, idx = 0;

	for ( ; idx < n && h >= 0; idx++) {
		h += (a[idx] == 'U' ? 1 : -1);
	}

//	cout << h << " " << idx << "\n";

	int cnt = 0;
	bool check = true;

	FOR(i, idx, n) {
		h += (a[i] == 'U' ? 1 : -1);
		if (h >= 0 && check) {
			cnt++;
			check = false;
		} else if (h < 0) {
			check = true;
		}
//		cout << h << " " << check << "\n";
	}

	cout << cnt;

	return 0;
}
