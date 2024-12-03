/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-27
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

	void add(const T& x) {
		H.push_back(x);
	}

	void init() {
		sort(H.begin(), H.end());
		H.resize(unique(H.begin(), H.end()) - H.begin());
	}

	int get(const T& x) const {
		return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
	}
};

const int maxN = 5e5 + 11;
const int blockSize = sqrt(maxN);

struct Query {
	int l, r, idx;

	Query() : l(0), r(0), idx(0) {}

	void read(const int& i) {
		cin >> l >> r;
		idx = i;
	}

	bool operator <(const Query &other) const {
		if (l / blockSize != other.l / blockSize) {
			return l < other.l;
		}

		return ((l / blockSize) % 2 ? r < other.r : r > other.r);
	}
};

int n, q, a[maxN], cnt[maxN];
Compressor<int> compress;

void add(int& ans, int idx) {
	cnt[a[idx]]++;
	if (cnt[a[idx]] == 2) ans++;
	if (cnt[a[idx]] == 3) ans--;
}

void del(int& ans, int idx) {
	cnt[a[idx]]--;
	if (cnt[a[idx]] == 2) ans++;
	if (cnt[a[idx]] == 1) ans--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("twotimes.inp", "r", stdin);
	freopen("twotimes.out", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		compress.add(a[i]);
	}

	compress.init();

	for (int i = 1; i <= n; ++i) {
		a[i] = compress.get(a[i]);
	}

	vector<Query> queries(q);
	vector<int> ans(q);

	for (int i = 0; i < q; ++i) {
		queries[i].read(i);
	}
	sort(queries.begin(), queries.end());

	int l = 1, r = 0, res = 0;
	for (Query x : queries) {
		while (l < x.l) del(res, l++);
		while (l > x.l) add(res, --l);
		while (r < x.r) add(res, ++r);
		while (r > x.r) del(res, r--);
		ans[x.idx] = res;
	}

	for (int answer : ans) cout << answer << '\n';
}
