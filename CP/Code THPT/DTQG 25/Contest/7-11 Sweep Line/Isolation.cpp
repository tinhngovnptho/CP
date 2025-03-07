  /*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif

using namespace std;

const int MAXN = 1e5 + 11;

int n, q;
pair<int, int> a[MAXN], queries[MAXN];
int res[MAXN];
bool used[MAXN];

void run_case(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 1; i <= q; ++i) {
		cin >> queries[i].first;
		queries[i].second = i;
	}
	sort(a + 1, a + n + 1);
	sort(queries + 1, queries + n + 1, greater<pair<int, int> >());

	int idx = n;
	int cnt = 0;
	for (int i = 1; i <= q; ++i) {
		while (idx && a[idx].first > queries[i].first) {
			used[a[idx].second] = true;
			cnt++;
			if (used[a[idx].second - 1]) cnt--;
			if (used[a[idx].second + 1]) cnt--;
			idx--;
		}
		res[queries[i].second] = cnt;
	}
	for (int i = 1; i <= q; ++i) cout << res[i] << ' ';
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("Isolation.inp", "r", stdin);
	freopen("Isolation.out", "w", stdout);

	int tests = 1;
//	cin >> tests;
	while (tests--) run_case();
//	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
