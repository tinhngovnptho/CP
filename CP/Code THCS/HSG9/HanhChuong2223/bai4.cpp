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

int n, a[MAXN], prefix[MAXN], suffix[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("bai4");
	cin >> n;
	int cnt1 = 0, cnt2 = 0;
	FORE(i, 1, n) {
		cin >> a[i];
		cnt1 += (a[i] == 1);
		cnt2 += (a[i] == 2);
	}

	int ans = min(cnt1, cnt2);

	/// build prefix
	prefix[0] = 0;
	FORE(i, 1, n) prefix[i] = prefix[i - 1] + (a[i] == 2);

	/// build suffix
	suffix[n + 1] = 0;
	FORDE(i, n, 1) suffix[i] = suffix[i + 1] + (a[i] == 1);

	FORE(i, 1, n) {
//		cout << prefix[i] << " " << suffix[i + 1] << "\n";
		minimize(ans, prefix[i] + suffix[i + 1]);
	}

	cout << ans;

	return 0;
}
