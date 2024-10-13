// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
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

bool isPalin(string s) {
	REP(i, sz(s)) if (s[i] != s[sz(s) - i - 1]) return false;
	return true;
}

void process(void) {
	string s; cin >> s;
	vector<pair<int, int> > v;
	REP(i, sz(s) - 1) {
		string tmp = s.substr(i + 1) + s.substr(0, i + 1);
//		cerr << tmp << "\n";
		if (isPalin(tmp)) {
			v.push_back(mp(i + 1, i + 2));
		}
	}
	if (!sz(v)) {
		cout << -1;
	} else {
		cout << sz(v) << "\n";
		REP(i, sz(v)) cout << v[i].fi << " " << v[i].se << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
