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

int cnt[MAXN];

void process(void) {
	int n, k; cin >> n >> k;
	REP(i, n) {
		int x; cin >> x;
		cnt[x]++;
	}
	priority_queue<int> pq;
	FORE(i, 1, k) if (cnt[i]) pq.push(cnt[i]);
	int res = 0;
	while (pq.size() > 1) {
		int top1 = pq.top(); pq.pop();
		int top2 = pq.top(); pq.pop();
		top1--; top2--; res += 2;
		if (top1 > 0) pq.push(top1);
		if (top2 > 0) pq.push(top2);
	}
	cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
