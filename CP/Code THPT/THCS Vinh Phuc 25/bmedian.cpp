/*
	Author: tinhnopro
	created: 19.01.2025 17:05:29
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "bmedian"

using namespace std;

using i64 = long long;


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	int n; 
	cin >> n; 
	vector<int> a(n + 2, -1); 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}

	if (n == 2) {
		cout << min(a[1], a[2]); 
		return 0; 
	}

	int ans = -1; 

	vector<int> tmp;

	for (int i = 1; i <= n - 2; ++i) {
		tmp.clear(); 
		tmp.push_back(a[i]); 
		tmp.push_back(a[i + 1]); 
		tmp.push_back(a[i + 2]); 

		sort(tmp.begin(), tmp.end());
		ans = max(ans, tmp[1]); 
	}

	cout << ans; 
}