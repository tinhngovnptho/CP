#include <bits/stdc++.h>
using namespace std;

#define NAME "NVT"
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair <int, int>
#define vi vector <int>
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (__typeof(a) i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (__typeof(b) i = (b); i >= (a); --i)
#define FORI(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

template <class T> bool umin(T& a, const T& b) { return  a > b ? a = b, 1 : 0; }
template <class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(T& a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }

int n, k, h[100005];

void solve() {
	cin >> n >> k;
	FOR(i, 1, n) cin >> h[i];

	int l = 1, r = *max_element(h+1, h+n+1), ans = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2, cnt = 0;
		FOR(i, 1, n) if (h[i] >= mid) cnt++;
		cnt <= k ? r = mid - 1, ans = mid : l = mid + 1;
	}

	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen(NAME ".inp", "r")) {
		assert(freopen(NAME ".inp", "r", stdin));
		assert(freopen(NAME ".out", "w", stdout));
	}
	int tests; cin >> tests;
	while (tests--) {
		solve();
	}
}
