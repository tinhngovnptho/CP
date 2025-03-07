/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-26
**/

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif // LOCAL

#include <bits/stdc++.h>

#define TMP 0

using namespace std;

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
	static_assert(D >= 1, "Init Error");
	template <typename... Args>
	vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};

template <typename T>
struct vec<T, 1> : public vector<T> {
	vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};

const int maxN = 2e5 + 11;
const int MAX = 1e6 + 11;
const int inf = 1e9 + 11;

int n, a[maxN];
vector<int> pos[MAX];

struct FendwickTree {
	int bit[MAX];

	void update(int u, int val) {
		for (; u < MAX; u += u & -u) {
			maximize(bit[u], val);
		}
	}
	int get(int u) const {
		int res = 0;
		for (; u; u -= u & -u) {
			maximize(res, bit[u]);
		}
		return res;
	}
} BIT;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("robotv4.inp", "r", stdin);
	freopen("robotv4.out", "w", stdout);
#endif // LOCAL

	cin >> n;
	for (int i = 1; i <= 2 * n + 1; ++i) {
		cin >> a[i];
	}

	vector<int> set1, set2;

	set1.push_back(TMP);
	set2.push_back(TMP);

	for (int i = 1; i <= n + 1; ++i) if (a[i] != a[i + 1]) set1.push_back(a[i]);
	for (int i = 2 * n + 1; i > n + 1; --i) if (a[i] != a[i - 1]) set2.push_back(a[i]);

	while (set1.size() > 1 && set1.back() == a[n + 1]) set1.pop_back();
	while (set2.size() > 1 && set2.back() == a[n + 1]) set2.pop_back();

	for (int i = 1; i < (int)set2.size(); ++i) {
		pos[set2[i]].push_back(i);
	}

	int res = 0;

	for (int i = 1; i < (int)set1.size(); ++i) {
		for (int j = pos[set1[i]].size() - 1; ~j; --j) {
			int d = pos[set1[i]][j];
			int cur = BIT.get(d - 1) + 1;
			maximize(res, cur);
			BIT.update(d, cur);
		}
	}

	cout << set1.size() + set2.size() - 2 - res;
}
