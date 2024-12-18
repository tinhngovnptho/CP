/**
 * author: tinhnopro (tinh nop)
 * created: 2024-12-05
**/
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#include <bits/stdc++.h>

#define TASK "seq"

using namespace std;

const int maxN = 3e5 + 11;

int n, k, a[maxN], cnt[maxN];

void compress(int *a, int n) {
	vector<int> h;
	for (int i = 1; i <= n; ++i) h.push_back(a[i]);

	sort(h.begin(), h.end());
	h.resize(unique(h.begin(), h.end()) - h.begin());

	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(h.begin(), h.end(), a[i]) - h.begin() + 1;
	}
}

int update(const int& idx, int diff) {
	if (cnt[a[idx]] == 0) diff++;
	return diff;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(false);
	if (fopen(TASK ".inp", "r")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	compress(a, n);
	priority_queue<int> pq;

	pq.push(0);

	int ans = 0;
	for (int l = 1, r = 0; l <= n; ++l) {
		while (r + 1 <= n && max(pq.top(), cnt[a[r + 1]] + 1) >= (r + 1 - l + 1) - k) {
			r++;
			cnt[a[r]]++;
			pq.push(cnt[a[r]]);
		}

		if (pq.top() >= r - l + 1 - k) ans = max(ans, r - l + 1);

		if (cnt[a[l]] == pq.top()) pq.pop();
		cnt[a[l]]--;
		pq.push(cnt[a[l]]);
	}

	cout << ans;
}
