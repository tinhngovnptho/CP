/*
	Author: Tinhnopro (Tinh nop)
	From: CHV Phu Tho
 */
#include<bits/stdc++.h>

namespace std {
	// optimize min max
	template<typename T1, typename T2> bool maximize(T1 &a, T2 b) { return a < b ? a = b, 1 : 0; }
	template<typename T1, typename T2> bool minimize(T1 &a, T2 b) { return a > b ? a = b, 1 : 0; }
	// vector
	template<typename T, int D> struct vec : public vector<vec<T, D - 1>> {
		static_assert(D >= 1, "Init error");
		template<typename... Args>
			vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
	};
	template<typename T> struct vec<T, 1> : public vector<T> {
		vec(int n = 0, T val = T()) : vector<T>(n, val) {}
		template<typename InputIt>
			vec(InputIt first, InputIt last) : vector<T>(first, last) {}
	};
	// size
	template<typename T> int Size(const T &a) {  return a.size(); }
}
using namespace std;


void process(void) {
	string s; 
	cin >> s; 
	int n = Size(s);
	s = " " + s;
	vector<vector<int>> pos(2);
	for (int i = 2; i <= n; ++i) {
		if (s[i] == s[i - 1]) {
			// cerr << i << ' ';
			pos[0].push_back(i); 
		} else if (s[i] == s[i - 2]) {
			pos[1].push_back(i);
			// cerr << i << ' ';
		}
	}

	int q;
	cin >> q; 
	while (q--) {
		int L, R; cin >> L >> R; 
		if (Size(pos[0])) { 
			int Left = lower_bound(pos[0].begin(), pos[0].end(), L + 1) - pos[0].begin();
			int Right = upper_bound(pos[0].begin(), pos[0].end(), R) - pos[0].begin() - 1;
			if (Right - Left + 1 > 0) {
				// cerr << Left << ' ' << Right << '\n';
				cout << "yes\n";
				continue;
			} 
		}
		if (Size(pos[1])) {
			int Left = lower_bound(pos[1].begin(), pos[1].end(), L + 2) - pos[1].begin();
			int Right = upper_bound(pos[1].begin(), pos[1].end(), R) - pos[1].begin() - 1;
			if (Right - Left + 1 > 0) {
				// cerr << Left << ' ' << Right << '\n';
				cout << "yes\n";
				continue;
			}
		}
		cout << "no\n";
	}
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "a"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
