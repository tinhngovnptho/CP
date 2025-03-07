#include <bits/stdc++.h>

#define TASK "segtree_itladder"
#define TIME ((1.0 * clock()) / CLOCKS_PER_SEC)

using namespace std;

inline void setIO() {
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}
}

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int64_t randInt(int64_t l, int64_t r) {
	return uniform_int_distribution<int64_t> (l, r) (rng);
}

char randaz() {
	return char('a' + randInt(0, 25));
}

char randAZ() {
	return char('A' + randInt(0, 25));
}

void gentest() {
	ofstream cout(TASK".inp");

	int n = randInt(1, 100);
	int t = randInt(1, 100);

	cout << n << ' ' << t << '\n';

	for (int i = 1; i <= t; ++i) {
		int type = randInt(1, 2);
		int l = randInt(1, n / 2);
		int r = randInt(l + 1, n);

		cout << type << ' ' << l << ' ' << r;

		if (type == 1) {
			cout << randInt(1e8, 1e9) << ' ' << randInt(1e8, 1e9);
		}

		cout << '\n';
	}

	cout.close();
}

int32_t main() {
	for (int i = 1; i <= 100; ++i) {
		gentest();
	}
}

