#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
#define FORA(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long

template <class X, class Y> bool umin(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool umax(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(const T &a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template <class T> T abs(const T &a) { return a >= 0 ? a : -a; }

const int MAX_N = 1e5+11;

pair<int, int> a[MAX_N];
int n, k, b[MAX_N];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i].fi;
		a[i].se = i;
	}

	sort(a+1, a+n+1);

	FOR(i, 1, n) {
		b[i] = a[i].fi;
	}

	FOR(i, 1, n-1) {
		int idx = lower_bound(b+i+1, b+n+1, 2*k - b[i]) - b;
		if (a[idx].fi + a[i].fi == 2*k) {
			cout << a[i].se << " " << a[idx].se << "\n";
			return 0;
		}
	}

	cout << "0 0";

	return 0;
}
