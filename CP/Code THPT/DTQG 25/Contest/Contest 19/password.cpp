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

string a, b; 

const int MAXN = 1e6 + 11; 
const int64_t MOD = 1e9 + 7, BASE = 311;

struct Hash {
	int64_t h[MAXN], pow[MAXN];
	int sz; 

	void init(string &s) {
		sz = Size(s);	
		s = ' ' + s;
		pow[0] = 1; 
		for (int i = 1; i <= sz; ++i) {
			pow[i] = pow[i - 1] * BASE % MOD;
			h[i] = (h[i - 1] * BASE % MOD + (s[i] - 'a' + 1)) % MOD;
		}
	}
} hash1, hash2;

namespace Sub1 {
	void solve(void) {
		string pref_a = "";
		set<string> s; 
		for (int i = 0; i < Size(a); ++i) {
			pref_a.push_back(a[i]);
			string pref_b = "";
			for (int j = 0; j < Size(b); ++j) {
				pref_b.push_back(b[j]);
				s.insert(pref_a + pref_b);
			}
		}
		cout << Size(s) << '\n';
	}
}

namespace Sub2 {
	void solve(void) {
		hash1.init(a);
		hash2.init(b);
		vector<int64_t> s;
		for (int i = 1; i <= hash1.sz; ++i) {
			for (int j = 1; j <= hash2.sz; ++j) {
				s.emplace_back((hash1.h[i] * hash1.pow[j] % MOD + hash2.h[j]) % MOD);
			} 
		}
		sort(s.begin(), s.end());
		s.resize(unique(s.begin(), s.end()) - s.begin());
		cout << Size(s);
	}
}

void process(void) {
	cin >> a >> b;
	if (Size(a) <= 200 && Size(b) <= 200) return void(Sub1::solve());
	if (Size(a) <= 2000 && Size(b) <= 2000) return void(Sub2::solve());

}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	#define name "password"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
