/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> pos[26];

void run_case(void) {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < int(s1.size()); ++i) pos[s1[i] - 'a'].push_back(i + 1);
	int64_t ans = 0, pre = 0;
	for (int i = 0; i < int(s2.size()); ++i) {
		int x = s2[i] - 'a';
		if (pos[x].empty()) {
			cout << -1;
			return ;
		}

		ans -= pre;

		int id = upper_bound(pos[x].begin(), pos[x].end(), pre) - pos[x].begin();

		if (id >= int(pos[x].size())) {
			ans += s1.size();
			id = 0;
		}
		ans += pos[x][id];
		pre = pos[x][id];
	}
	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
