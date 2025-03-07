#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e5 + 11, MAX = 1e6 + 11;

int d, n, sum[MAXN], cnt[MAX];

void process(void) {
	cin >> d >> n;
	FORE(i, 1, n) {
		int x; cin >> x;
		sum[i] = (sum[i - 1] + x % d) % d;
	}
	cnt[0] = 1;
	int64 ans = 0;
	FORE(i, 1, n) {
		ans += cnt[sum[i]];
		cnt[sum[i]]++;
	}
	cout << ans;
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("daychiahet");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
