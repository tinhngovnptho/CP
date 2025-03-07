#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, b, a) for (int i = (b); i >= (a); i--)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long

template<class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template<class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template<class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; }

#define MAX_N	100100
int a[MAX_N], b[MAX_N], n;

int bsearch(int x) {
	if (a[1] > x) return 1;
	if (a[n] < x) return n;

	int L = 1, R = n;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] > x) R = mid - 1;
		else L = mid + 1;
	}
	return abs(a[L] - x) < abs(a[R] - x) ? L : R;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, n) {
		cin >> b[i];
	}

	sort(a+1, a+n+1);

	int ans = 2e9+11;

	FOR(i, 1, n) {
		int idx = bsearch(-b[i]);
		ans = min(ans, abs(a[idx] + b[i]));
	}

	cout << ans;
}
