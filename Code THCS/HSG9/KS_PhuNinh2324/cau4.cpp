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

const int MAXN = 1e5 + 11;

long long sum = 0, cnt[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("cau4");
	int n, tests; cin >> n >> tests;
	REP(i, n) {
		int x; cin >> x;
		cnt[x]++;
	}

	REP(i, MAXN) sum += 1LL * i * cnt[i];
	cout<<sum;
	int u, v;
	while(tests--) {
		cin >> u >> v;
		sum += 1LL * v * cnt[u];
		sum -= 1LL * u * cnt[u];
		cnt[v] += cnt[u];
		cnt[u] = 0;
		//cout << sum << "\n";
	}

	return 0;
}
