/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 11; 

int n, k; 
int par[MAXN], sz[MAXN];

void run_case(void) {
	cin >> k >> n;
	par[1] = 0; 
	sz[1] = 1;
	for (int i = 2; i <= n; ++i) {
		cin >> par[i];
		for (int j = i; j; j = par[j]) sz[j]++;
	}
	int cnt = 0;
	for (int i = n; i >= 1; --i) if (sz[i] >= k) {
		cnt++;
		for (int j = par[i]; j ; j = par[j]) sz[j] -= sz[i]; 
	}

	cout << cnt; 
} 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("v8org.inp", "r", stdin);
	freopen("v8org.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
