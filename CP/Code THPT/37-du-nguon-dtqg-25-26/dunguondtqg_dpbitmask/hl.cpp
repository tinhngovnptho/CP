/*
	Author: tinhnopro
	created: 26.02.2025 13:03:06
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "hl"

using namespace std;

using i64 = long long;

int n, h[105], minPrime[105], idx[105];
vector<int> primes; 
int stt[105], dp[105][1 << 20]; 

constexpr int onbit(const int& mask, const int& pos) {
	return mask | (1 << pos);
}

void sieve(int sz) {
	iota(minPrime + 2, minPrime + sz + 1, 2);
	for (int i = 2; i * i <= sz; ++i) if (minPrime[i] == i) {
		for (int j = i * i; j <= sz; j += i) 
			if (minPrime[j] == j) minPrime[j] = i;
	}

	for (int i = 1; i <= sz; ++i) if (minPrime[i] == i) primes.push_back(i);
	
	for (size_t i = 0; i < primes.size(); ++i) idx[primes[i]] = i; 
}

int getDisplay(int x) {
	int mask = 0; 
	while (x != 1) {
		mask = onbit(mask, idx[minPrime[x]]);
		x /= minPrime[x]; 
	}

	return mask; 
}

int32_t main() {
	ios::sync_with_stdio(false);	
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> h[i]; 
	}

	sieve(60); 

	for (int i = 1; i <= 60; ++i) {
		stt[i] = getDisplay(i); 
		// cout << stt[i] << ' ';
	}

	int sz = (int) primes.size();

	memset(dp, 0x3f, sizeof(dp));

	dp[0][0] = 0;


	for (int i = 1; i <= n; ++i) {
		for (int mask = 0; mask < (1 << sz); ++mask) {
			for (int val = 1; val < 2 * h[i]; ++val) {
				if ((stt[val] & mask) == 0) { 
					dp[i][mask | stt[val]] = min(dp[i][mask | stt[val]], dp[i - 1][mask] + abs(h[i] - val));
				}
			}
		}
	}

	int ans = 1e9 + 5; 

	for (int mask = 0; mask < (1 << sz); ++mask) {
		ans = min(ans, dp[n][mask]);
	}

	// for (int i = 1; i <= n; ++i) {
	// 	for (int mask = 0; mask <= 5; ++mask) cout << dp[i][mask] << ' '; 
	// 	cout << '\n';
	// }
	cout << ans; 
}