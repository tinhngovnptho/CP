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

const int mxN = 1e5+11;

int n, q, query[mxN];
bool used[mxN], selected[mxN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen(NAME ".inp", "r")) {
		assert(freopen(NAME ".inp", "r", stdin));
		assert(freopen(NAME ".out", "w", stdout));
	}
	cin >> n >> q;
	memset(used, false, sizeof(used));
	memset(selected, false, sizeof(selected));
	FOR(i, 1, q) {
		cin >> query[i];
		selected[query[i]] = true;
	}
	FORD(i, q, 1) {
		if (!used[query[i]]) {
			cout << query[i] << "\n";
		}
		used[query[i]] = true;
	}
	FOR(i, 1, n) if (!selected[i]) cout << i << "\n";
}
