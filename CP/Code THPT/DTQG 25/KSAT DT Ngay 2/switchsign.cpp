/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-14
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#define ALL(v) (v).begin(), (v).end()
#define ssize(s) (int) (s).size()

#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template <typename A, typename B> bool minimize(A &a, B b)  { return a > b ? a = b, true : false; }
template <typename A, typename B> bool maximize(A &a, B b)  { return a < b ? a = b, true : false; }
//} end of template

const int MAXN = 5e5 + 11;

struct Query {
	char op;
	int val;

	void read() {
		cin >> op >> val;
	}
};

int n, q, a[MAXN];
Query queries[MAXN];

namespace Sub1 {

	bool check(void) {
		return (n <= 5000 && q <= 5000);
	}

	void solve(void) {
		while (q--) {
			char op;
			int val;
			cin >> op >> val;
			if (op == '<') {
				for (int i = 1; i <= n; ++i) if (a[i] < val) a[i] = -a[i];
			} else {
				for (int i = 1; i <= n; ++i) if (a[i] > val) a[i] = -a[i];
			}
		}
		for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
	}
}

namespace Sub2 {

	bool check(void) {
		for (int i = 1; i <= q; ++i) {
			if (queries[i].op == '<') return false;
			if (queries[i].val < 0) return false;
		}
		return true;
	}

	void solve(void) {
		int last = n - 1;
		vector<pair<int, int> > v;
		for (int i = 1; i <= n; ++i) {
			v.emplace_back(a[i], i);
		}
		sort(ALL(v));
		for (int i = 1; i <= q; ++i) {
			int val = queries[i].val;
			int idx = upper_bound(ALL(v), make_pair(val, 0)) - v.begin();
			if (idx > last) continue ;
			last = idx - 1;
		}

		for (int i = last; i < n; ++i) {
			a[v[i].second] = -v[i].first;
		}
		for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
	}
}


void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	if (Sub1::check()) return void(Sub1::solve());

	for (int i = 1; i <= q; ++i) {
		queries[i].read();
	}

	if (Sub2::check()) return void(Sub2::solve());
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	file("switchsign");
//__________________________________
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
