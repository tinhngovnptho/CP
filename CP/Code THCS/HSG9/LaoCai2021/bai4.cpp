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

bool isPalin(string s) {
	REP(i, sz(s) / 2) if (s[i] != s[sz(s) - i - 1]) return false;
	return true;
}

void process(void) {
	string s; getline(cin, s);
	stringstream ss(s);
	string word;
	map<string, int> mp; int cnt1 = 0, cnt2 = 0;
	while (ss >> word) {
		mp[word]++;
		if (isPalin(word)) cnt2++;
	}
	FORA(it, mp) if (it->se == 1) cnt1++;
	cout << cnt1 << "\n" << cnt2;
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("bai4");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
