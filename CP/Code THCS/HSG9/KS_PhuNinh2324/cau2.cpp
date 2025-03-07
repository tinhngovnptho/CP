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
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

int n, m, k;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("cau2");
	cin >> n >> m >> k;

	int group = 1, cntElm = n / m;
	FOR(i, 1, m) {
		if (cntElm >= k) break;
		k -= cntElm;
		cntElm = (n - i) / m + 1;
		group++;
//		cout << k << " ";
	}

	if(group == 1) k++;
//	cout << k << " " << m << " " << group << "\n";
	cout << (k - 1) * m + (group - 1);


	return 0;
}
