#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define ll  long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi  vector<int>
#define fi  first
#define se  second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORX(i, a, b, x) for (int i = (a), _b = (b); i <= _b; i += (x))
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = (int) 5e5 + 11;
//const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct Compress {
    vi v;
    void add(int x) {
        v.push_back(x);
    }

    void init(void) {
        sort(ALL(v));
        v.resize(unique(ALL(v)) - v.begin());
    }

    int getZ(int x) {
        return lower_bound(ALL(v), x) - v.begin() + 1;
    }
} zip;

struct DSU {
    int lab[MAXN];

    DSU() {
        memset(lab, -1, sizeof lab);
    }

    int find_par(int u) {
        return lab[u] > 0 ? lab[u] = find_par(lab[u]) : u;
    }

    void union_set(int u, int v) {
        u = find_par(u);
        v = find_par(v);

        if (u == v) return ;
        lab[u] += lab[v];
        lab[v] = u;
    }
} dsu;

int m, n, l[MAXN], r[MAXN];

void process(void) {
    cin >> m >> n;
    zip.add(m + 1);
    FOR(i, 1, n) {
        cin >> l[i] >> r[i];
        zip.add(l[i]);
        zip.add(r[i]);
    }
    zip.init();
    FOR(i, 1, n) {
        l[i] = zip.getZ(l[i]);
        r[i] = zip.getZ(r[i]);
    }

    int res = 0;

    FORD(i, n, 1) {
        int R = dsu.find_par(r[i] + 1);
        bool ok = 0;
        while (l[i] <= r[i]) {
            int id = dsu.find_par(l[i]);
            ok = ok | (bool) (l[i] < id);
            dsu.lab[l[i]] = R;
            l[i] = id + 1;
        }
        if (!ok) res++;
    }
    cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("C");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
