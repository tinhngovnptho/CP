/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 411;

int n;
vector <int> adj[MAXN];

void maximize(int &x, int y) {
	if (x < y) x = y;
}

int dfs(int u) {
	if (adj[u].empty()) return 1;
	vector <int> q;
	for (int &v : adj[u]) {
		 q.push_back(dfs(v));
	}

	sort(q.begin(), q.end(), greater<int>());

	int ans = 0;

	for (int i = 0; i < q.size(); ++i) {
		maximize(ans, q[i] + i);
	}

	return ans;
}

void run_case(void) {
	cin >> n;
	for (int i, m; cin >> i >> m; ) {
		for (int j = 1, x; j <= m; ++j) {
			cin >> x;
			adj[i].push_back(x);
		}
	}

	cout << dfs(1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("stone1.inp", "r", stdin);
	freopen("stone1.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
