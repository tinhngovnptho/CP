/*
	Author: tinhnopro
	created: 19.01.2025 21:07:22
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "cshorten"

using namespace std;

using i64 = long long;

vector<int> pos[26]; 

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	string s, t; 
	cin >> s >> t; 

	for (int i = 0; i < int(t.size()); ++i) {
		pos[t[i] - 'a'].push_back(i); 
	}

	int rev_pos = 0, res = 1; 

	for (char c : s) {
		int id = c - 'a'; 
		if (pos[id].empty()) {
			cout << -1; 
			return 0; 
		}
		int p = upper_bound(pos[id].begin(), pos[id].end(), rev_pos) - pos[id].begin();
		// cout << pos[id][p] << ' ' << rev_pos << '\n';
		if (p >= int(pos[id].size())) {
			res++; 
			p = 0; 
		}
		rev_pos = pos[id][p]; 
	}

	cout << res;
}