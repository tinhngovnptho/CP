#include <bits/stdc++.h>

#define setIO(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

using namespace std;

template <typename T> inline int isize(const T& a) { return a.size(); }

template <typename T1, typename T2> bool maximize(T1& a, T2 b) { return a < b ? a = b, true : false; }
template <typename T1, typename T2> bool minimize(T1& a, T2 b) { return a > b ? a = b, true : false; }

const int maxN = 1e5 + 11;

int n, a[maxN], b[maxN];
map<int, int> mark;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); setIO("smgame");

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}

	for (int i = 1; i <= n; ++i) {
		mark[a[i]] = 1;
	}

	bool ok = 0;

	int mx = 0;

	set<int> res;

	for (int i = 1; i <= n; ++i) {
		ok |= mark[b[i]];
		if (mark[b[i]]) res.insert(b[i]);
		maximize(mx, b[i]);
	}

	if (res.find(mx) == res.end()) {
		cout << -1;
		return 0;
	}

	if (!ok) {
		cout << -1;
		return 0;
	}

	int cnt = 0;

	for (int i = 1; i <= n; ++i) {
		if (a[i] != b[i]) cnt++;
	}

	cout << cnt;
}

