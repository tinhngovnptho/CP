#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("TOWER.inp", "r", stdin);
	freopen("TOWER.out", "w", stdout);

	int n, x; cin >> n;
	vector<int> d(n, 1e9+11);
	FOR(i, 1, n) {
		cin >> x;
		int idx = lower_bound(ALL(d), x) - d.begin();
//		cout << idx << ": ";
		d[idx] = x;
//		FOR(j, 0, d.size()-1) if (d[j] != 1e9+11) cout << d[j] << " ";
//		cout << "\n";
	}

	FOR(j, 0, d.size()-1) if (d[j] == 1e9 + 11) {
		cout << j;
		return 0;
	}

	return 0;
}
