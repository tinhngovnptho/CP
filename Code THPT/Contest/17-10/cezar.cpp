// Author: tinhnopro (tinhngo)
#include<bits/stdc++.h>

#define name "cezar"
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
using pi32 = pair<int, int>;
using pi64 = pair<ll, ll>;

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

int n, k;
vi adj[MAXN];
int sum[MAXN], child[MAXN], depth[MAXN];

void countChild(int u, int par) {
	child[u] = 1; 
	for (int v : adj[u]) if (v != par) {
		countChild(v, u);
		child[u] += child[v];
	}
}

int getcentroid(int u, int par) {
	for (int v : adj[u]) if (v != par && child[v] > n / 2) {
		return getcentroid(v, u);
	}
	return u;
}

void dfs(int u, int par) {
	child[u] = 1;
	for (int v : adj[u]) if (v != par) {
		depth[v] = depth[u] + 1;
		sum[v] += depth[v];
		dfs(v, u);
		sum[u] += sum[v];
		child[u] += child[v];
	}
}

void process(void) {
	cin >> n >> k;
	FOR(i, 1, n - 1) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	countChild(1, 1);
	int centroid = getcentroid(1, 1);

	memset(child, 0, sizeof child);
	dfs(centroid, centroid);

	ll ans = 0;

	for (int v : adj[centroid]) ans += sum[v];

	vi res;
	FOR(i, 1, n) if (i != centroid) res.emplace_back(child[i]);

	sort(all(res), greater<int>());

	FOR(i, 0, k - 1) ans -= res[i];

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
