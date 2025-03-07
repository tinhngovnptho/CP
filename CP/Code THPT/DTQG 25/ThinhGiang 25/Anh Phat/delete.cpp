/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 11;

int a[MAXN], b[MAXN];


void run_case(void) {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 2; i <= n; ++i) b[i] = a[i] - a[i - 1];

	int res = 0;

	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("delete.inp", "r", stdin);
	freopen("delete.out", "w", stdout);

	int tests = 1;
	cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
