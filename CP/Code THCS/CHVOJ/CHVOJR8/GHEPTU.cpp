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

bool case1(char x) {
	return x == 'b' || x == 'c' || x == 'd';
}

bool case2(char x) {
	if (case1(x) == false) return true;
	return false;
}

bool cvcv(string d) {
	return case1(d[2]) && case2(d[3]);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("GHEPTU.inp", "r", stdin);
	freopen("GHEPTU.out", "w", stdout);

	int t; cin >> t; while(t--) {
		string s; cin >> s;

		string ans = "";
		while(s.size() >= 4) {
			if (cvcv(s.substr(0, 4))) {
				ans += s.substr(0, 2) + '.';
				s.erase(0, 2);
			} else {
				ans += s.substr(0, 3) + '.';
				s.erase(0, 3);
			}
		}
		ans += s;
		cout << ans << "\n";
	}

	return 0;
}
