#include <bits/stdc++.h>

#define TASK ""

using namespace std;

inline void setIO() {
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}
}

//mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
bitset<100000001> bs;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	int d = sqrt(n / 2), d2 = sqrt(n);

	for (int i = 0; i <= d; ++i) {
		for (int j = i; j <= d2; ++j) {
			if (i * i + j * j > n) break;
			bs[i * i + j * j] = true;
		}
	}

	cout << bs.count() - 1;
}

