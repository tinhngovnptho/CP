#include <bits/stdc++.h>

#define TASK ""
#define TIME ((1.0 * clock()) / CLOCKS_PER_SEC)

using namespace std;

using int64 = long long;

inline void setIO() {
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}
}

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int64 randInt(int64 l, int64 r) {
	return uniform_int_distribution<int64> (l, r) (rng);
}

char randaz() {
	return char('a' + randInt(0, 25));
}

char randAZ() {
	return char('A' + randInt(0, 25));
}

void gentest() {
	ofstream cout(TASK".inp");

	cout.close();
}

int32_t main() {
	for (int i = 1; i <= 100; ++i) {
		gentest();

		system(TASK".exe");
		system(TASK"_bf.exe");

		if (system("fc "TASK".out "TASK".ans") != 0) {
			return 0;
		}
	}
}
