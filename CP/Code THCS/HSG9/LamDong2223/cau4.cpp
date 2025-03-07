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

const int MAXN = 1001, INF = 2e9 + 11;

int n, m;
int64 dp[MAXN];

struct Data {
	int l, r, c;
	friend istream& operator >>(istream &stream, Data &a) {
		stream >> a.l >> a.r >> a.c;
		return stream;
	}
} a[MAXN];

bool cmp(const Data &a, const Data &b) {
	if (a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}

void process(void) {
	cin >> n >> m;
	REP(i, m) cin >> a[i];
	sort(a, a + m, cmp);
	memset(dp, 0x3f, sizeof dp);
	REP(i, m) {
		FORE(j, a[i].l, a[i].r) {
			if (a[i].l == 0) minimize(dp[j], a[i].c);
			else minimize(dp[j], dp[a[i].l - 1] + a[i].c);
		}
		REP(j, i) if (a[j].r >= a[i].l)
			FORE(k, a[i].l, a[j].r) minimize(dp[k], dp[a[i].l] + a[i].c);
	}
	cout << dp[n];
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("cau4");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
