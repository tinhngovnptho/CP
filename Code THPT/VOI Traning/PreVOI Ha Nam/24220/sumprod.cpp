#include <bits/stdc++.h>

using namespace std;

template <typename T> inline int isize(const T& a) { return a.size(); }

template <typename T1, typename T2> bool maximize(T1& a, T2 b) { return a < b ? a = b, true : false; }
template <typename T1, typename T2> bool minimize(T1& a, T2 b) { return a > b ? a = b, true : false; }

const int maxN = 1e5 + 11;
const int mod = 998244353;

int n, q, k, a[maxN];
int sum[2 * maxN];

struct query_t {
	int type, l, r, x;

	void read() {
		cin >> type;
		if (type == 2) {
			cin >> l >> r;
		} else {
			cin >> l >> r >> x;
		}
	}
};

query_t queries[maxN];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

namespace Sub1 {

	bool check() {
		return n <= 200 && q <= 200;
	}

	void solve() {
		for (int i = 1; i <= q; ++i) {
			if (queries[i].type == 1) {
				for (int j = queries[i].l; j <= queries[i].r; ++j) {
					add(a[j], queries[i].x);
				}
			} else {
				int res = 0;
				for (int _i = queries[i].l; _i <= queries[i].r; ++_i) {
					for (int j = _i + k; j <= queries[i].r; ++j) {
						add(res, 1LL * a[_i] * a[j] % mod);
					}
				}
				cout << res << '\n';
			}
		}
	}
}

namespace Sub2 {

	bool check() {
		return n <= 5000 && q <= 5000;
	}

	void solve() {

		for (int idx = 1; idx <= q; ++idx) {
			int l = queries[idx].l;
			int r = queries[idx].r;
			int x = queries[idx].x;
			if (queries[idx].type == 1) {
				for (int i = l; i <= r; ++i) {
					add(a[i], x);
				}
				for (int i = l; i <= n; ++i) {
					sum[i] = sum[i - 1];
					add(sum[i], a[i]);
				}
			} else {
				int res = 0;

				for (int i = l; i + k <= r; ++i) {
					int sum_range = (sum[r] - sum[i + k - 1] + mod) % mod;
					add(res, 1LL * sum_range * a[i] % mod);
				}

				cout << res << '\n';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("sumprod.inp", "r", stdin);
	freopen("sumprod.out", "w", stdout);

	cin >> n >> q >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1];
		add(sum[i], a[i]);
	}

	for (int i = 1; i <= q; ++i) queries[i].read();

	if (Sub1::check()) return Sub1::solve(), 0;
	return Sub2::solve(), 0;
}
