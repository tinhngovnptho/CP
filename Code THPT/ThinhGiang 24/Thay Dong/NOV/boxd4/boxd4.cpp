/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-25
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

using namespace std;

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

template <class T>
struct Compressor {
	vector<T> H;

	void add(const T &x) {
		H.push_back(x);
	}

	void init() {
		sort(H.begin(), H.end());
		H.resize(unique(H.begin(), H.end()) - H.begin());
	}

	int get(const T &x) const {
		return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
	}
};


const int mod = 1e9 + 7;
const int64_t infll = (int64_t) 1e18 + 11;
const int maxN = 1e6 + 11;

using ii = pair<int64_t, int>;

int n;
ii a[maxN], dp[maxN];
Compressor<int64_t> compress;

void fixmod(int &a) {
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}

void combine(ii &a, ii b) {
	if (a.first > b.first) {
		a = b;
	} else if (a.first == b.first) {
		a.second += b.second;
		fixmod(a.second);
	}
}

struct FendwickTree {
	ii bit[maxN];
	int sz;

	FendwickTree() {
		sz = 0;
	}

	void init() {
		for (int i = 1; i <= sz; ++i) {
			bit[i] = {infll, 0};
		}
	}

	void update(int u, ii val) {
		for (; u; u -= u & -u) {
			combine(bit[u], val);
		}
	}

	ii get(int u) const {
		ii res = {infll, 0};
		for (; u <= sz; u += u & -u) {
			combine(res, bit[u]);
		}
		return res;
	}
} fen;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("boxd4.inp", "r", stdin);
	freopen("boxd4.out", "w", stdout);
#endif // LOCAL

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a + 1, a + n + 1, [&](const ii &x, const ii &y) {
		if (x.second == y.second) return x.first < y.first;
		return x.second < y.second;
	});

//	int64_t ans = infll;
//	int cnt = 0;
//
//	for (int i = n; i; --i) {
//		dp[i] = {infll, 0};
//		int64_t cost = a[i].second - a[i].first;
//		for (int j = i + 1; j <= n; ++j) if (a[i].first <= a[j].second) {
//			combine(dp[i], {dp[j].first + cost, dp[j].second});
//		}
//
//		if (dp[i] == make_pair(infll, 0)) dp[i] = {a[i].second, 1};
//
//		minimize(ans, dp[i].first);
//	}
//
//	for (int i = 1; i <= n; ++i) if (ans == dp[i].first) {
//		cnt += dp[i].second;
//		fixmod(cnt);
//	}
//
//	cout << cnt;
// Brute
	for (int i = 1; i <= n; ++i) {
		compress.add(a[i].first);
		compress.add(a[i].second);
	}

	compress.init();
	fen.sz = compress.H.size();
	fen.init();

	debug(compress.H);

	int64_t ans = infll;
	int cnt = 0;

	for (int i = n; i; --i) {
		dp[i] = {infll, 0};

		int id1 = compress.get(a[i].first);
		int id2 = compress.get(a[i].second);

		ii cur = fen.get(id1);

		if (cur == dp[i]) {
			dp[i] = {a[i].second, 1};
		} else combine(dp[i], {cur.first + a[i].second - a[i].first, cur.second});

		debug(dp[i]);

		fen.update(id2, dp[i]);

		minimize(ans, dp[i].first);
	}

	for (int i = 1; i <= n; ++i) if (ans == dp[i].first) {
		cnt += dp[i].second;
		fixmod(cnt);
	}

	cout << cnt;
}
