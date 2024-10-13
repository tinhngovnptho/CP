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

string s;

void process(void) {
	cin >> s;
	if (sz(s) < 2) return void(cout << -1 << "\n");
	REP(i, sz(s)) {
		if (i < sz(s) - 1 && s[i] == s[i + 1]) return void (cout << 0 << "\n");
		if (i < sz(s) - 2 && s[i] == s[i + 2]) return void(cout << 0 << "\n");
	}
	cout << 1 << "\n";
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("a");
	int t = 1;
	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
