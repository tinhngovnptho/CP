#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= (b); ++i)
#define FORA(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int) (x).size()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) {
	return a < b ? a = b, 1 : 0;
}

template <class X, class Y> bool minimize(X &a, const Y &b) {
	return a > b ? a = b, 1 : 0;
}

const int MAXN = 1e6+11;

int n, x;
long long prefix_sum[MAXN], prefix_sumOdd[MAXN], p[MAXN];

void solve(void) {
	cin >> n;
	prefix_sum[0] = prefix_sumOdd[0] = p[0] = 0;
	FOR(i, 1, n) {
		cin >> x;
		prefix_sum[i] = prefix_sum[i-1] + x;
		prefix_sumOdd[i] = prefix_sumOdd[i-1];
		if (i & 1) prefix_sumOdd[i] += x;
//		cout << prefix_sum[i] << " " << prefix_sumOdd[i] << "\n";
		p[i] = prefix_sum[i] - 2 * prefix_sumOdd[i];
	}
	sort(p+0, p+n+1);
//	FOR(i, 0, n) cout << p[i] << " ";
	FOR(i, 0, n-1) if (p[i] == p[i+1]) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("DOCSACH.inp", "r", stdin);
	freopen("DOCSACH.out", "w", stdout);

	int t; cin >> t; while(t--) {
		solve();
	}

	return 0;
}
