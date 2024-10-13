#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define ll long long
#define ld long double
#define ull unsigned long long

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

bool isSpecial(int x) {
	int cnt = 0;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			cnt++;
			while (x % i == 0) x /= i;
		}
	}
	return cnt >= 3;
}

bool isPal(int x) {
	int tmp = x, res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res == tmp;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	int l, r, ans = 0;
	cin >> l >> r;

	FOR(i, l, r) {
		if (isSpecial(i) && isPal(i)) ans += i;
	}

	cout << ans;

	return 0;
}
