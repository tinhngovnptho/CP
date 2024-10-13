#include 						<bits/stdc++.h>

using namespace 				std;

#define int                     long long
#define db                      double
#define fi						first
#define	se						second
#define pb						push_back
#define FOR(i, l, r)			for(int i = l; i <= r; i ++)
#define FORD(i, r, l)			for(int i = r; i >= l; i --)
#define FILL(arr, x)			memset(arr, x, sizeof arr)
#define ll						long long
#define ii						pair<int, int>
#define KAnt;					signed main
#define Sonic					ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ONBIT(mask, i)			(mask | (1ll << (i)))
#define OFFBIT(mask, i)			(mask &~ (1ll << (i)))
#define MASK(i) 				(1ll << (i))
#define __builtin_popcount		__builtin_popcountll
#define C_BIT(mask)				__builtin_popcount(mask)
#define BIT(mask, i)			(mask & (1ll << (i)))
#define md(l, r)                ((l + r) >> 1)
#define left(id)                (id << 1)
#define right(id)               ((id << 1) + 1)
#define TASK					"KANT"
#define vi                      vector<int>
#define vvi                     vector<vector<int>>

const int maxN = 1e5 + 6;

int n, m;

vector<int> Edge[maxN];

ii A[maxN];

int res[maxN];

bool Visit[maxN];

struct DSU {
	int sz[maxN];
	int pa[maxN];

	void make_set() {
		FOR(i, 1, n) {
			pa[i] = i;
			sz[i] = 1;
		}
	}

	int get_root(int x) {
		if (x == pa[x])
			return x;
		return pa[x] = get_root(pa[x]);
	}

	void union_set(int x, int y) {
		x = get_root(x);
		y = get_root(y);

		if (x == y)
			return;

		if(sz[x] < sz[y])
			swap(x, y);

		sz[x] += sz[y];
		pa[y] = x;
	}
} DSU1;

KAnt() {
	Sonic

    if (fopen(TASK".INP", "r")) {
    	freopen(TASK".INP", "r", stdin);
    	freopen(TASK".OUT", "w", stdout);
    }

    cin >> n >> m;

    FOR(i, 1, n) {
    	cin >> A[i].fi;
    	A[i].se = i;
    }

    FOR(i, 1, m) {
    	int u, v;
    	cin >> u >> v;
    	Edge[u].pb(v);
    	Edge[v].pb(u);
    }

    sort(A + 1, A + n + 1);

    FILL(res, -1);

    DSU1.make_set();

    FORD(i, n, 1) {
    	int w = A[i].fi;
    	int u = A[i].se;

    	Visit[u] = true;

    	for(int v: Edge[u])
    		if (Visit[v] == true) {
    		 	DSU1.union_set(v, u);
    		}

    	int siz = DSU1.sz[DSU1.get_root(u)];

    	if (res[siz] == -1)
    		res[siz] = w;
    }

    FORD(i, n, 1)
    	res[i] = max(res[i], res[i + 1]);

    FOR(i, 1, n) {
    	cout << res[i] << " ";
    }

	return 0;
}
