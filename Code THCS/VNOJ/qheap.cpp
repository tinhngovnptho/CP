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
#define rep(i, a, b) for (__typeof(a) i = (a); i < (b); ++i)
#define down(i, b, a) for (__typeof(b) i = (b); --i >= a; )

template <class T> bool umin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template <class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> string to_str(T& a, int p = -1) { stringstream ss; p >= 0 ? ss << fixed << setprecision(p) << a : ss << a; return ss.str(); }


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen(NAME ".inp", "r")) {
		assert(freopen(NAME ".inp", "r", stdin));
		assert(freopen(NAME ".out", "w", stdout));
	}

	priority_queue <int> pq;
	while (!pq.empty()) pq.pop();
	string s;
	while (cin >> s) {
		if (s[0] == '+') {
			s.erase(0, 1);
			if (sz(pq) < 15000) pq.push(atoi(s.c_str()));
		} else {
			if (pq.empty()) continue;
			int mx = pq.top();
			while (!pq.empty() && pq.top() == mx) pq.pop();
		}
	}
	set <int, greater<int> > res;
	while (!pq.empty()) {
		res.insert(pq.top());
		pq.pop();
	}
	cout << sz(res) << "\n";
	for (set<int>::iterator it = res.begin(); it != res.end(); ++it) cout << *it << "\n";
}

/**-----------------------------------------
---------- Author: tinhnopro ---------------
----------While(!Die) Code();---------------
---------//-------NVT-------//--- /\_/\ ----
-------------------------------- (= ._.) ---
-------------------------------- />WA  \> **/
