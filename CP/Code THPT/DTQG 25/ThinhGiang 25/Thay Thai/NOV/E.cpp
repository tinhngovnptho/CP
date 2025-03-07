/**
 *	author:  tinhnopro (tinh nop)
 *	created: 2024-11-13
**/
#include <bits/stdc++.h>

using namespace std;

//{ template
#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...) 0
#endif // LOCAL

#define ALL(v) (v).begin(), (v).end()
#define ssize(s) (int) (s).size()

#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template <typename A, typename B> bool minimize(A &a, B b)  { return a > b ? a = b, true : false; }
template <typename A, typename B> bool maximize(A &a, B b)  { return a < b ? a = b, true : false; }
//} end of template

const int MAXN = 1e5 + 11;
const int64_t INF = 1e18 + 11;

int n;
int64_t c[MAXN];
int pos[MAXN];
char a[MAXN];

bool check_bracket_open(const char &x) {
	return (x == '(' || x == '{' || x == '[');
}

bool check_bracket_close(const char &x) {
	return (x == ')' || x == '}' || x == ']');
}

bool check_bracket_pair(const char &x, const char &y) {
	if (x == ')' && y == '(') return true;
	if (x == '}' && y == '{') return true;
	if (x == ']' && y == '[') return true;
	return false;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	file("E");

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		c[i] += c[i - 1];
	}

	auto cost = [&] (int l, int r) -> int64_t {
		return c[r] - c[l - 1];
	};

	stack<int> st;

	int64_t ans = -INF;

	for (int i = 1; i <= n; ++i) {
		if (check_bracket_open(a[i])) st.push(i);
		else {
			if (st.empty()) {
				st.push(i);
				continue;
			}
			int last = st.top();
			if (check_bracket_pair(a[i], a[last])) {
				maximize(ans, cost(last, i));
				debug(i, last, ans);
				pos[i] = last;
				if (pos[last - 1] != 0) {
					if (cost(pos[last - 1], i) > cost(last, i)) {
						maximize(ans, cost(pos[last - 1], i));
						pos[i] = pos[last - 1];
					}
				}
				st.pop();
			} else st.push(i);
		}
	}

	if (ans == -INF) cout << 0;
	else cout << ans;
}
