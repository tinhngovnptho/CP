/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

const int MAXN = 2e5 + 11;

int n, m, all;
int a[MAXN];

const int MOD = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int sub(int a, int b) {
	int ret = a - b;
	if (ret < 0) ret += MOD;
	return ret;
}

int Sum(int x) {
	return (1LL * x * (x + 1) / 2) % MOD;
}

namespace Sub2 {

	bool check(void) {
		return n <= 5000;
	}

	void solve(void) {
		int res = 0;
		unordered_set<int> s;
		for (int i = 1; i <= n; ++i) {
			int sum = 0;
			s.clear();
			for (int j = i; j <= n; ++j) {
				if (s.empty() || s.count(a[j]) == 0) add(sum, a[j]);
				s.insert(a[j]);
				add(res, sum);
			}
		}
		cout << res << "\n";
	}
}

namespace Subfull {

	vector<int> pos[MAXN];

	struct Compressor {
		vector<int> H;

		void add(const int &x) {
			H.push_back(x);
		}

		void init(void) {
			sort(H.begin(), H.end());
			H.resize(unique(H.begin(), H.end()) - H.begin());
		}

		int Get(const int &x) {
			return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
		}
	} compressor;

	void solve(void) {
		int res = 1LL * Sum(m) * Sum(n) % MOD;

		for (int i = 1; i <= n; ++i) compressor.add(a[i]);
		compressor.init();
		for (int i = 1; i <= n; ++i) pos[compressor.Get(a[i])].push_back(i);

		int sum = 0;

		for (int v : compressor.H) {
			int id = compressor.Get(v);
			for (int i = 0; i < int(pos[id].size()); ++i) {
				int Left = (i > 0 ? pos[id][i - 1] + 1 : 1);
				add(sum, (1LL * (pos[id][i] - Left + 1) * (n - pos[id][i] + 1) % MOD) * v % MOD);
			}
		}
		cout << sub(res, sum);
	}
}

void run_case(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	return void(Subfull::solve());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("happypar.inp", "r", stdin);
	freopen("happypar.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
