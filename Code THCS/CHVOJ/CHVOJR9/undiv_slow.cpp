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
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("undiv");
	int q; cin >> q;
	vector<long long> v;
	while(q--) {
		int n, k; cin >> n >> k;
		v.clear();
		int res = 0;
		while(sz(v) < k) {
			FOR(i, res + 1, res + n) v.push_back(i);
			res += n;
		}
		cout << v[k-1] << "\n";
	}

	return 0;
}
