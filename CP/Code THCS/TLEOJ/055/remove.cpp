#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;
typedef __int128_t int128;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void process(void) {
	int n, k; cin >> n >> k;
	ordered_set s;
	FORE(i, 0, n) s.insert(i);
	vector<int> d;
	while (!s.empty()) {
		int cnt = 0;
		d.clear();
		FORA(it, s) {
			if (cnt % k == 0) d.push_back(*it);
			cnt++;
		}
		REP(i, sz(d)) {
			cout << d[i] << " ";
			s.erase(s.find(d[i]));
		}
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("remove");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
