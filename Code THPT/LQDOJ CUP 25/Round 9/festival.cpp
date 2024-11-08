/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;


void run_case(void) {
	int n;
	cin >> n;
	for (int i = 1, u, v; i <= n; ++i) {
		cin >> u >> v; 
	}

	cout << n / 2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("festival.inp", "r", stdin);
	freopen("festival.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
