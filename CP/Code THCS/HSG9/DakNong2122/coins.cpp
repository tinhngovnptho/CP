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

typedef pair<int, int> pii;

const int MAXN = 1e5 + 11;

int n, m;
pii a[MAXN];

bool cmp(const pii &a, const pii &b) {
	if (a.se - a.fi == b.se - b.fi) return a.fi > b.fi;
	return a.se - a.fi < b.se - b.fi;
}

void process(void) {
	cin >> n >> m;
	FORE(i, 1, n) cin >> a[i].fi;
	FORE(i, 1, n) cin >> a[i].se;
	sort(a + 1, a + n + 1, cmp);
	FORE(i, 1, n) {
		if (a[i].se - a[i].fi <= m) {
			m += a[i].fi;
		} else break;
	}
	cout << m;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
