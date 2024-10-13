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

int n, k, a[MAXN], cnt[MAXN];

void zip(void) {
	vector<pair<int, int>> v;
	FORE(i, 1, n) v.push_back(make_pair(a[i], i));
	sort(ALL(v));
	int last = 0, cnt = 0;
	FOR(i, 0, sz(v)) {
		if (v[i].fi != last) {
			cnt++;
			last = v[i].fi;
		}
		a[v[i].se] = cnt;
	}
}

void process(void) {
	cin >> n >> k;
	FORE(i, 1, n) cin >> a[i];
	int l = 1, cur = 0;
	long long ans = 0;
	zip();
	FORE(r, 1, n) {
		if (cnt[a[r]] == 0)	cur++;
		cnt[a[r]]++;
		while (cur > k) {
			if (cnt[a[l]] == 1) cur--;
			cnt[a[l]]--;
			l++;
		}
		ans += r - l + 1;
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
