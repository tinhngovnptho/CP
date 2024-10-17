// Author: tinhnopro (tinhngo)
#include<bits/stdc++.h>

#define name "nx"
#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()
#define szv(v) int((v).size())
#define sqr(x) 1ll * (x) * (x)
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

using namespace std;

using ll = long long;
using db = long double;
using vi = vector<int>;

template<class T> using pairD = pair<T, T>;  

template<class T> using vector2d = vector<vector<T>>;

template<class X, class Y> bool maximize(X &a, Y b) { 
	return a < b ? a = b, 1 : 0; 
}

template<class X, class Y> bool minimize(X &a, Y b) { 
	return a > b ? a = b, 1 : 0; 
}

template<class T> T Abs(const T &x) {
	return x < 0 ? -x : x;
}	
//_______________________________________________________________________

const int MAXN = 4000 + 11; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7; 
// const int INF = 1e9 + 11; // const ll INFF = 1e18 + 11; 

int n, k;
string s[MAXN];

namespace Sub1 {
	string minSubstr[2][111];
	
	void init(int i) {
		int sz = szv(s[i]);
		s[i] = " " + s[i];
		// cout << s[i] << el;
		FOR(len, 1, sz) {
			FOR(d, 1, len) minSubstr[i][len].push_back('z');
			FOR(l, 1, sz - len + 1) {
				if (s[i].substr(l, len) < minSubstr[i][len]) {
					minSubstr[i][len] = s[i].substr(l, len);
					// cout << s[i].substr(l, len) << el;
				}
			}
			// cout << minSubstr[i][len] << el;
		}
	}

	void solve(void) {
		init(0);
		init(1);
		string res;
		FOR(i, 1, k) res.push_back('z');
		FOR(i, 1, k) {
			int j = k - i;
			string d = minSubstr[0][i] + minSubstr[1][j];
			if (minSubstr[0][i] == "" || minSubstr[1][j] == "") continue;
			if (d < res) {
				res = d; 
			}
			// cout << d << el;
		}
		cout << res << el;
	}
}

namespace Sub2 {
	string dp[55][555];
	string minSubstr[55][555];

	void getmin(string &a, string b) {
		if (a == "") {
			a = b;
		} else if (a > b) {
			a = b;
		}
	}

	void solve(void) {

		FOR(i, 0, n - 1) {
			int sz = szv(s[i]);
			s[i] = " " + s[i];
			FOR(len, 1, sz) FOR(l, 1, sz - len + 1) {
				getmin(minSubstr[i][len], s[i].substr(l, len));
			}
		}

		FOR(j, 1, k) dp[1][j] = minSubstr[0][j];

		FOR(i, 2, n) {
			dp[i][1] = minSubstr[i - 1][1];
			FOR(j, 2, k) {
				FOR(t, 1, j - 1) if (j - t <= szv(s[i - 1])) {
					getmin(dp[i][j], dp[i - 1][t] + minSubstr[i - 1][j - t]);
				}
			}
		}
		cout << dp[n][k];
	}
}

void process(void) {
	cin >> n >> k;
	FOR(i, 0, n - 1) {
		cin >> s[i];
	}

	if (n == 2 && szv(s[1]) <= 100 && szv(s[2]) <= 100) return void(Sub1::solve());
	Sub2::solve();
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);

	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//___________________________________
	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
	return 0;
}
