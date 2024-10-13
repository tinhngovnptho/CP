// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

const long long INF = 1e18 + 11;

long long N, M, S;

bool checkRec(long long a, long long b) {
	/// 2S - N * a * (b - 1) * b - a * b * (a - 1) = 2 * X * a * b
	long long tmp1 = 2 * S - N * a * (b - 1) * b - a * b * (a - 1);
	long long tmp2 = 2 * a * b;
	if (tmp1 % tmp2) return false;
	long long x = tmp1 / tmp2;
	long long i = x / N + 1;
	long long j = x % N + 1;
	if (i + b - 1 > M) return false;
	if (j + a - 1 > N) return false;
	return true;
}

void process(void) {
	cin >> M >> N >> S;
	long long ans = INF;
	for (long long b = 1; b * (b - 1) <= 2 * S && b <= M; ++b) {
		for (long long a = 1; N * a * b * (b - 1) + a * (a - 1) * b <= 2 * S && a <= N; ++a) {
			if (checkRec(a, b)) {
				minimize(ans, a * b);
				break;
			}
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("hcn");
	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
