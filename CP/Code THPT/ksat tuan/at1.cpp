/*
	Author: tinhnopro
	created: 06.03.2025 08:57:52
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "at1"
#define int long long 

using namespace std;

using i64 = long long;

const int  maxN = 3e5 + 5; 
const int INF =  (int) 1e18 + 11;

int n, m, s; 
int a[maxN], d[maxN][2]; 
vector<pair<int, int> > adj[maxN]; 

struct Data {
	int u, d_u, type; 
	
	Data(int _u = 0, int _d_u = 0, int _type = 0) : u(_u), d_u(_d_u), type(_type) {}

	bool operator <(const Data& other) const {
		return d_u > other.d_u; 
	}
};

void Dijsktra(int s) {
	for (int i = 1; i <= n; ++i) {
		d[i][0] = d[i][1] = INF; 
	}

	d[s][0] = 0; 
	d[s][1] = a[s];
	
	priority_queue<Data> pq; 

	pq.emplace(s, d[s][0], 0); 
	pq.emplace(s, d[s][1], 1); 

	while (!pq.empty()) {
		int u = pq.top().u; 
		int d_u = pq.top().d_u;
		int type = pq.top().type;

		// cout << u << ' ' << d_u << ' ' << type << '\n';

		pq.pop();

		if (d_u > d[u][type]) continue;

		for (auto x : adj[u]) {
			int v = x.first; 
			int w = x.second; 

			/*
				d[v][0] = d[u][0] + w
				d[v][1] = d[u][0] + w + a[v]
				d[v][1] = d[u][1] + w 
			*/

			if (d[v][0] > d[u][0] + w) {
				d[v][0] = d[u][0] + w; 
				pq.emplace(v, d[v][0], 0);
			}

			if (min({d[v][1], d[u][0] + w + a[v], d[u][1] + w}) != d[v][1]) {
				d[v][1] = min(d[u][0] + w + a[v], d[u][1] + w); 

				pq.emplace(v, d[v][1], 1); 
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}
	
	cin >> n >> m >> s; 

	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}

	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w; 
		adj[u].emplace_back(v, w); 
		adj[v].emplace_back(u, w); 
	}

	Dijsktra(s); 

	int ans = 0; 

	for (int i = n; i; --i) {
		ans = max(ans, d[i][1]); 
	}

	cout << ans << ' ';

	for (int i = n; i; --i) {
		if (d[i][1] == ans) {
			cout << i; 
			return 0; 
		}
	}
}