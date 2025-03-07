#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;
typedef __int128_t int128;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAX = 5011;

int n, cnt[MAX];

void process(void) {
	cin >> n;
	REP(i, n) {
		int x; cin >> x;
		cnt[x]++;
	}
	int64 ans = 0;
	FOR(i, 1, MAX) if (cnt[i]) {
		ans += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2);
		FOR(j, i + 1, MAX) if (j + (j - i) < MAX && cnt[j] && cnt[j + (j - i)]) ans += 1LL * cnt[i] * cnt[j] * cnt[j + (j - i)];

	}
	cout << ans;
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("triple");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
