/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-18
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#define ssz(s) ((int) (s).size())
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;
typedef unsigned long long uint64;

const int maxN = 1e6 + 11;

int n, a[maxN];
bool mark[maxN];

bool check(int x) {
	for (int i = 1; i < 2 * n; ++i) mark[i] = a[i] >= x;

	if (mark[n] == mark[n - 1] || mark[n] == mark[n + 1]) return mark[n];

	int i = n - 1, j = n + 1;
	bool cur = mark[n];
	while (i > 0 && j < 2 * n && mark[i] == mark[j] && mark[i] != mark[i + 1]) {
		cur = mark[i];
		i--;
		j++;
	}
	return cur;
}

void tinhnop() {
	cin >> n;
	for (int i = 1; i < 2 * n; ++i) cin >> a[i];

	int lo = -1e9 - 11, hi = 1e9 + 11;
	while(hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("MEDPYRH.inp", "r", stdin);
	freopen("MEDPYRH.out", "w", stdout);

	int t; cin >> t;
	while (t--) tinhnop();
//	cerr << "\n[time] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
}
