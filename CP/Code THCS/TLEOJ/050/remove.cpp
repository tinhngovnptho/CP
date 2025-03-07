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

const int MAXN = 1e5 + 11;

int n, k, cnt[MAXN], d[MAXN];

void process(void) {
	cin >> n >> k;
	REP(i, n) {
		int x; cin >> x;
		cnt[x]++;
	}
	multiset<int, greater<int> > s;
	REP(i, n + 1) if (cnt[i]) s.insert(cnt[i]);
	int res = 0;
	vector<int> v(s.begin(), s.end());
	while (s.size() >= k) {
		REP(i, k) {
			s.erase(s.find(v[i]));
		}
		REP(i, k) if (v[i] - 1 > 0) s.insert(v[i] - 1);
		res++;
		v.assign(s.begin(), s.end());
	}
	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("remove");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
