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

const char open_bracket[] = "({[";
const char close_bracket[] = ")}]";

void process(void) {
	string s; getline(cin, s);
	stack<int> stk;
	REP(i, sz(s)) {
		REP(j, 3) if (s[i] == open_bracket[j]) {
			stk.push(i);
			break;
		}
		REP(j, 3) if (s[i] == close_bracket[j]) {
			if (s[stk.top()] != open_bracket[j]) {
				cout << "SAI " << i + 1;
				return;
			} else {
				stk.pop();
			}
		}
	}
	if (stk.empty()) {
		cout << "DUNG";
	} else {
		cout << "SAI ";
		int first;
		while (!stk.empty()) {
			first = stk.top(); stk.pop();
		}
		cout << first + 1;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("nvt");
//	int tests; cin >> tests; while (tests--)
	process();

	return 0;
}
