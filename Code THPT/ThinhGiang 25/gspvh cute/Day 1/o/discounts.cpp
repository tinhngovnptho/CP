// Author: tinhnopro (tinhngo)
#include<bits/stdc++.h>

#define name "discounts"
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

const int MAXN = 5e5 + 11; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7; 
// const int INF = 1e9 + 11; // const ll INFF = 1e18 + 11; 

struct Data {
	int type, cost, idx; 
	
	Data() {
		type = cost = idx = 0;
	} 

	void read(const int &x) {
		cin >> cost >> type;
		idx = x;
	}
};

int n, k;
Data d[MAXN];

bool cmp(const Data &a, const Data &b) {
	if (a.type == b.type) {
		return a.cost > b.cost;
	}
	return a.type > b.type;
}

void process(void) {
	int sub; cin >> sub;
	cin >> n >> k;
	FOR(i, 1, n) d[i].read(i);
	
	sort(d + 1, d + n + 1, cmp);
	
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
