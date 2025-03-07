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

int64_t sqr(int x) {
	return 1ll * x * x; 
}

void process(void) {
	string s; cin >> s; 
	vector<pair<char, int>> S;
	S.emplace_back(' ', 0); 
	for (int i = 0; i < Size(s); ++i) {
		if (s[i] == S.back().first) {
			S.back().second++;
		} else {
			S.emplace_back(s[i], 1);
		}
	} 
	int n = Size(S) - 1; 
	vector<int64_t> dp(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		if (S[i].second > 1) dp[i] += sqr(S[i].second);
		if (i >= 3 && S[i - 2].first == S[i].first) {
			int64_t res = dp[i - 3] + sqr(S[i - 2].second + S[i].second);
			if (S[i - 1].second > 1) res += sqr(S[i - 1].second);
			else continue;
			maximize(dp[i], res); 
		}
	}
	cout << dp[n] << '\n';
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "BALLOON"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
