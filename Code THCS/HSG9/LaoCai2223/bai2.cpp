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
typedef __int128_t int128;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

int get_len(int x) {
	int res = 0;
	for (; x; x /= 10) res++;
	return res;
}

int pow10(int l) {
	int res = 1;
	REP(i, l) res *= 10;
	return res;
}

int rev(int x) {
	int res = 0;
	for (; x; x /= 10) res = res * 10 + x % 10;
	return res;
}

int isValid(int x) {
	int cnt = 0;
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
		cnt++;
		while (x % i == 0) x /= i;
	}
	if (x > 1) cnt++;
	return cnt >= 3;
}

void process(void) {
	int a, b; cin >> a >> b;
	int cnt = 0;
	FORE(i, 1, 1e4) {
		int len = get_len(i);
		int dx1 = i * pow10(len) + rev(i);
		int dx2 = i * pow10(len - 1) + rev(i / 10);
		if (dx2 > b) break;
		if (a <= dx2 && isValid(dx2)) cnt++;
		if (a <= dx1 && dx1 <= b && isValid(dx1)) cnt++;
	}
	cout << cnt;
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("bai2");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
