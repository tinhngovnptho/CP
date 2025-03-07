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

const int MAXN = 2e5+ + 11;

int n, x, y, a[MAXN], prefix[MAXN];

void process(void) {
	cin >> n >> x >> y;
	FORE(i, 1, n) {
		cin >> a[i];
		prefix[i] = prefix[i-1] + (a[i] > 0);
	}

	int u = 0, v = 1e9+11;

	FORE(i, 1, n) {
		int L = i+1, R = n, res = 0;
		while (L <= R) {
			int mid = (L + R) / 2;
			int cntP = prefix[mid] - prefix[i-1];
			int cntD = mid - i + 1 - cntP;
			if (cntP >= x && cntD >= y) {
				res = mid;
				R = mid - 1;
			} else L = mid + 1;
		}
		if (res && v - u > abs(a[res]) - abs(a[i])) {
			u = abs(a[i]);
			v = abs(a[res]);
		}
	}

	if (u == 0 && v == 1e9 + 11) {
		cout << -1;
	} else {
		cout << u << " " << v;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
