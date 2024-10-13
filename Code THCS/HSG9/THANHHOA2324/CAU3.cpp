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

int reverse_num(int x) {
	int res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

int len(int x) {
	int res = 0;
	while (x) {
		res++;
		x /= 10;
	}
	return res;
}

bool isSpecial(int x) {
	int cnt = 0;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			cnt++;
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) cnt++;
	return cnt >= 3;
}

long long calc(int x) {
	long long res = 0;
	int r_i, l, x1, x2;
	FOR(i, 1, 1e4) {
		r_i = reverse_num(i);
		l = len(i);
		x1 = i * pow(10, l) + r_i;
		x2 = (i / 10) * pow(10, l) + r_i;
		if (x2 > x) break;
//		if (isSpecial(x1)) cout << x1 << " ";
//		if (isSpecial(x2)) cout << x2 << " ";
		res += (isSpecial(x1) && x1 <= x) ? x1 : 0;
		res += isSpecial(x2) ? x2 : 0;
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	int l, r;
	cin >> l >> r;

	cout << calc(r) - calc(l-1);

	return 0;
}
