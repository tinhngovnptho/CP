/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

int a[6];

void run_case(void) {
	for (int i = 0; i < 6; ++i) cin >> a[i];	
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("tetrahedron.inp", "r", stdin);
	freopen("tetrahedron.out", "w", stdout);

	int tests = 1;
	cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
