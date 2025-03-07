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

#define NAME	"undiv"

void gen(void) {
	ofstream out(NAME".inp");
	int q = rand() % 10;
	out << q << "\n";
	REP(i, q) {
		int n = rand() % 100;
		int k = rand() % 100;
		out << n << " " << k << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	file("nvt");

	REP(i, 100) {
		gen();
		system(NAME".exe");
		system(NAME"_slow.exe");
		if (system("fc "NAME".out "NAME".ans") != 0) {
			return 0;
		}
	}

	return 0;
}
