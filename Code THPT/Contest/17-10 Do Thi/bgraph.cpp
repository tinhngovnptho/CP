// Author: tinhnopro (tinhngo)
#include<bits/stdc++.h>

#define name "bgraph"
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
const int MOD = 998244353; 
// const int INF = 1e9 + 11; // const ll INFF = 1e18 + 11; 

int n, m;
vi adj[MAXN];
int c[MAXN];

int pow2(int x) {
	int res = 1, a = 2; 
	for (; x; x >>= 1, a = 1ll * a * a % MOD) if (x & 1) {
		res = 1ll * res * a % MOD;
	} 
	return res;
}

bool isCyc(int u, int color) {
	c[u] = color;
	for (int v : adj[u]) {
		if (c[v] == -1) {
			if (isCyc(v, 1 - color)) return true; 
		} else if ((c[u] + c[v]) % 2 == 0) {
			return true;
		}
	}
	return false;
}

int cnt[2]; 

void dfs(int u, int color) {
	c[u] = color;
	cnt[c[u]]++;
	for (int v : adj[u]) if (c[v] == -1) {
		dfs(v, 1 - color);
	}
}

void process(void) {
	cin >> n >> m;
	FOR(i, 1, m) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(c, -1, sizeof c);
	FOR(i, 1, n) if (c[i] == -1) {
		if (isCyc(i, 1)) {
			cout << 0;
			return ;
		}
	}
	

	memset(c, -1, sizeof c);

	int ans = 1;

	FOR(i, 1, n) if (c[i] == -1) {
		cnt[0] = cnt[1] = 0;
		dfs(i, 1);
		ans = (1ll * ans * (pow2(cnt[0]) + pow2(cnt[1])) % MOD) % MOD;
	}
	
	cout << ans;
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
