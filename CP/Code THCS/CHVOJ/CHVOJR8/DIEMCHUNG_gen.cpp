#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= (b); ++i)
#define FORA(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int) (x).size()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) {
	return a < b ? a = b, 1 : 0;
}

template <class X, class Y> bool minimize(X &a, const Y &b) {
	return a > b ? a = b, 1 : 0;
}

#define NAME	"DIEMCHUNG"

void gen(void) {
	ofstream out(NAME".inp");
	int n = rand() % 1000, k = max(0, n - rand() % 10);
	out << n << " " << k << "\n";
	FOR(i, 1, n) {
		int l = rand() % 100000;
		out << l << " " << l + rand() % 100 << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	FOR(i, 1, 100) {
		gen();
		system(NAME".exe");
		system(NAME"_slow.exe");
		if(system("fc "NAME".out "NAME".ans") != 0) {
			return 0;
		}
	}

	return 0;
}
