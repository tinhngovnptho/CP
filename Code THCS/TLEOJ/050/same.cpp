// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const int MAXN = 1e6 + 11;
const long long BASE = 13, MOD = 1e9 + 7;

int n, a[MAXN];
long long pw[MAXN], hashA[MAXN];

void init(void) {
	pw[0] = 1LL; hashA[0] = 0LL;
	FORE(i, 1, n) {
		pw[i] = pw[i - 1] * BASE % MOD;
		hashA[i] = (hashA[i - 1] * BASE % MOD + a[i]) % MOD;
	}
}

long long getHash(int l, int r) {
	return (hashA[r] - hashA[l - 1] * pw[r - l + 1] + MOD * MOD) % MOD;
}

unordered_map<long long, int> max_h, min_h;

bool check(int len) {
	max_h.clear(); min_h.clear();
	FORE(i, 1, n - len + 1) {
		long long id = getHash(i, i + len - 1);
		if (max_h.count(id)) {
				maximize(max_h[id], i);
		} else max_h[id] = i;
		if (min_h.count(id)) {
				minimize(min_h[id], i);
		} else min_h[id] = i;
	}
	FORA(it, max_h) {
		if (it->se - min_h[it->fi] >= len) return true;
	}
	return false;
}

void process(void) {
	cin >> n;
	FORE(i, 1, n) {
		cin >> a[i];
	}
	init();
	int L = 1, R = n, res = 0;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (check(mid)) {
			res = mid;
			L = mid + 1;
		} else R = mid - 1;
	}
	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("same");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
