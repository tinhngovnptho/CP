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

#define NAME	"CAU4"

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randInt(ll l, ll r) {
	return uniform_int_distribution<ll> (l, r) (rng);
}

void gen(void) {
	ofstream inp(NAME ".inp");

	int N = randInt(1, 1000);
	inp << N << "\n";

	FOR(i, 1, N) {
		inp << randInt(-1000000, 1000000) << " ";
	}

        inp.close();
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);

	srand(time(NULL));

	FOR(i, 1, 100) {
		gen();
		system(NAME ".exe");
		system(NAME "_slow.exe");
		if (system("fc " NAME ".out " NAME ".ans") != 0) {
			cout << "WA";
			return 0;
		}
	}

	return 0;
}
