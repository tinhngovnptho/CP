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

int n, m, solved[21];

void solve() {
	memset(solved, 0, sizeof(solved));
	cin >> n >> m;
	bool isBeaScore = true;
	char x;
	FOR(i, 1, n) {
		bool solvedFull = 1, isSolved = 0;
		FOR(j, 1, m) {
			cin >> x;
			bool pr = x - '0';
			solved[j] |= pr;
			solvedFull &= pr; isSolved |= pr;
//			cout << solvedFull << " ";
		}
		cout << "\n";
		if (solvedFull || !isSolved) isBeaScore = false;
	}
	FOR(i, 1, m) if (!solved[i]) {
		return void(cout << "NO\n");
	}
	cout << (isBeaScore ? "YES" : "NO") << "\n";
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
