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

#define MAXN 	3000300

pair<int, int> a[MAXN];
int n;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a+1, a+n+1);

	ll cnt = 0, res = 0;
	a[0].first = -1e9-11, a[0].second = -1e9-11;
	FOR(i, 1, n) {
		if (a[i].first != a[i-1].first) {
			res += cnt * (cnt - 1) / 2;
			cnt = 1;
		} else if (a[i].second != a[i-1].second) cnt++;
//		cerr << cnt << " ";
	}

	res += cnt * (cnt - 1) / 2;

	cout << res;

	return 0;
}
