#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; ++i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	map<string, int> cnt;
	FOR(i, 0, n) {
		string s; cin >> s;
		cnt[s]++;
	}

	FORA(it, cnt) {
		if (it->se & 1) {
			cout << it->first;
			return 0;
		}
	}

	return 0;
}
