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

int x[4] = {9, 1, 3, 7};

int rev(int x) {
	int res = 0;
	for (; x; x /= 10) res = res * 10 + x % 10;
	return res;
}

void solve1(int64 k) {
	if (k == 1) {
		cout << 1;
		return ;
	}
	vector<int> a;
	a.push_back(1);
	while (a.back() != 10) {
		a.push_back(rev(a.back()) + 2);
	}
//	REP(i, sz(a)) cout << a[i] << "\n";
	int n = a.size() - 1;
	k = k % n;
//	cout << k << " ";
	cout << a[k - 1];
}

void solve2(int64 k) {
	int d = k % 4;
	if (k > 4) cout << k / 4 - (k % 4 == 0);
	cout << x[d];
}

void process(void) {
	int64 k; cin >> k;
	int64 res = 1;
	solve1(k);
	cout << "\n";
	solve2(k);
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("bai5");
	int t = 1;
//	cin >> t;
	while (t--) process();
	return 0;
}

// author: tinhnopro
