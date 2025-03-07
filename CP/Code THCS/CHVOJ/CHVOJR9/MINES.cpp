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

const int MAXN = 1011, INF = 1e9 + 11;

char a[MAXN][MAXN], b[MAXN][MAXN];
int n, m, k;

void reset(void) {
	FORE(i, 1, n) FORE(j, 1, m) a[i][j] = b[i][j];
}

void print(void) {
	FORE(i, 1, n) {
		FORE(j, 1, n) cout << a[i][j] << " ";
		cout << "\n";
	}
}

bool check(int x) {
	int cnt_boom = 0;
	FORE(i, 1, n) {
		FORE(j, 1, m) {
			if (a[i][j] == 'x') {
				a[i][j] = '.';
				cnt_boom++;
				FORE(k, j + 1, min(j + 2 * x, m))  {
					if (a[i][k] == '#') break;
					if (a[i][k] == 'x') a[i][k] = '.';
				}
			}
		}
//		print(); cout << "\n";
	}
//	cout << cnt_boom << "\n";
	return cnt_boom <= k;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("MINES");
	cin >> n >> m >> k;
	FORE(i, 1, n) FORE(j, 1, m) {
		cin >> a[i][j];
		b[i][j] = a[i][j];
	}

//	cout << check(506);

	int L = 0, R = MAXN, ans = -1;
	while(L <= R) {
		int mid = (L + R) / 2;
		if (check(mid)) {
			ans = mid;
			R = mid - 1;
		} else L = mid + 1;
		reset();
	}

	cout << ans;

	return 0;
}
