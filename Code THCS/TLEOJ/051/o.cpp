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

bool sub1 = true;
const int MAXN = 5e4 + 11;
vector<char> a[MAXN];
int n, m;

bool check(int i, int j, int d, int r) {
	if (sub1) return true;
	FORE(x, j, j + r - 1) if (a[i][x] == '1' || a[i + d - 1][x] == '1') return false;
	FORE(y, i, i + d - 1) if (a[y][j] == '1' || a[y][j + r - 1] == '1') return false;
	return true;
}

void process(void) {
	cin >> n >> m;
	REP(i, n) REP(j, m) {
		char x; cin >> x;
		a[i].push_back(x);
		if (x == '1') sub1 = false;
	}
	long long cnt = 0;
	FORE(d, 1, n) FORE(r, 1, m) {
		if (sub1) {
			cnt += 1LL * (n - d + 1) * (m - r + 1);
			continue;
		}
		REP(i, n - d + 1) REP(j, m - r + 1) if (check(i, j, d, r)) cnt++;
	}
	cout << cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("o");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
