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

const int MAXN = 2e5 + 11;

int n;
string s;

struct Hash {
	static const int MOD = 1e9 + 7;
	static const int BASE = 311;
	long long pw[MAXN], h[MAXN];

	void init(string &s, int len) {
		s = " " + s;
		pw[0] = 1, h[0] = 0;
		FORE(i, 1, len) {
			pw[i] = pw[i - 1] * BASE % MOD;
			h[i] = (h[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
		}
	}
	long long get(long long l, long long r) {
		return (h[r] - h[l - 1] * pw[r - l + 1] % MOD + MOD * MOD) % MOD;
	}
} hashT;

map<long long, int> mp;

bool check(int x) {
	mp.clear();
	FORE(i, 1, n - x + 1) {
		long long id = hashT.get(i, i + x - 1);
		if (mp[id]) return true;
		else mp[id]++;
	}
	return false;
}

void process(void) {
	cin >> n >> s;
	hashT.init(s, n);
	int l = 0, r = sz(s), ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}

	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
