#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair <int, int>
#define vi vector <int>
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (__typeof((a)) i = (a); i < (b); ++i)
#define down(i, b, a) for (__typeof(b) i = (b)-1; i >= (a); --i)
#define fora(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

#define NAME ""

template <class T> bool umin(T& a, const T& b) { return  a > b ? a = b, 1 : 0; }
template <class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(T& a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }
template <class T> T abs(T a) { return a >= 0 ? a : -a; }

const int mxN = 1e5+11;

int n, dp[mxN], a[mxN];

bool isSqr(int x) {
	return sqrt(x) == ceil(sqrt(x));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen(NAME ".inp", "r")) {
		freopen(NAME ".inp", "r", stdin);
		freopen(NAME ".out", "w", stdout);
	}
	cin >> n;
	rep(i, 1, n+1) {
		cin >> a[i];
	}
	memset(dp, 0, sizeof(dp));
	rep(i, 1, n+1) {
		rep(j, (int) max(1, i-10), min(n, i+10)+1) {
			if (isSqr(abs(a[i] - a[j]))) {
				if (!dp[j]) umax(dp[i], dp[j] + 2);
			} else umax(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp+1, dp+n+1);
}
