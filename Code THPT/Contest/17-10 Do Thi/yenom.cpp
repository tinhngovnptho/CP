// Author: tinhnopro (tinhngo)
#include<bits/stdc++.h>

#define name "yenom"
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
const int INF = 1e9 + 11;  const ll INFF = (ll) 1e18 + 11; 

int n;
ll a[MAXN];
ll T, d[MAXN];

void Dijsktra() {
	FOR(i, 1, a[1] - 1) d[i] = INFF;
	d[0] = 0;
	priority_queue<pairD<ll>, vector<pairD<ll>> , greater<pairD<ll>>> pq; 
	pq.push({0, 0});
	
	while (!pq.empty()) {
		int u = pq.top().se; 
		ll d_u = pq.top().fi; 
		pq.pop();
		if (d_u > d[u]) continue; 
		FOR(i, 1, n) {
			int v = (d[u] + a[i]) % a[1];
			if (d[v] > d[u] + a[i]) {
				d[v] = d[u] + a[i];
				pq.push({d[v], v});
			}
		}
	}
}

void process(void) {
	cin >> n >> T;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	Dijsktra();
	ll ans = 0;

	FOR(i, 0, a[1] - 1) if (d[i] != INFF) {
		ll high = T;
		while ((high - d[i]) % a[1] != 0) high--;
		ans += max(0ll, (high - d[i]) / a[1] + 1);
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
