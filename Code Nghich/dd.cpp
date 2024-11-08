/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 11; 

int n, m, cnt[MAXN], a[MAXN];

void minimize(int &a, int b) {
	if (a > b) a = b; 
}
 
void run_case(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int ans = (int) 1e9 + 11; 

	for (int i = 1, j = 1, count = 0; i <= n; ++i) {
		if (i > 1) {
			cnt[a[i - 1]]--;
			if (!cnt[a[i - 1]]) count--;
		}
		while (count < m) {
			j++;
			if (cnt[a[j]] == 0) count++;
			cnt[a[j]]++;
		}
		if (count == m) {
			minimize(ans, j - i + 1);
		}
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
