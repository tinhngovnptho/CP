/*
	Author: Tinhnopro (Tinh nop)
	From: CHV with luv <3
	while (true) coding();
*/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second

#define all(v) (v).begin(), (v).end()
#define size(v) int32_t((v).size())
#define eb emplace_back

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

#define Mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | Mask(i))
#define offbit(i, mask) (mask & ~(Mask(i)))
#define cntbit(x) __builtin_popcountll(x)
#define Log2(x) (63 - __builtin_clzll(x))

using namespace std;

using db = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int64_t>;

template<class X, class Y> bool maximize(X &a, Y b) { 
	return a < b ? a = b, 1 : 0; 
}

template<class X, class Y> bool minimize(X &a, Y b) { 
	return a > b ? a = b, 1 : 0; 
}

// const int dx[8] = {+1, -1, +0, +0, +1, -1, +1, -1}, dy[8] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int INF = 1e9 + 11, MAXN = 1e5 + 11, MOD = 1e9 + 7; 
// const int64_t INFF = (int64_t) 1e18 + 7;
//_______________________________________________________________________________________________

struct Query {
	int type, a, b, idx; 
	Query() {
		type = a = b = idx = -1; 
	}
	Query(int _t, int _a, int _b, int _i) {
		type = _t; 
		a = _a;
		b = _b; 
		idx = _i;
	}

	void Read(const int &i) {
		cin >> type >> a >> b;
		idx = i;
	}
};

struct Compressor {
	vector<int> z;
	
	void add(const int &x) {
		z.eb(x);
	}

	void Compress() {
		sort(all(z));
		z.resize(distance(z.begin(), unique(all(z))));
	}

	int get(int x) {
		return lower_bound(all(z), x) - z.begin() + 1; 
	}
} zip;

int n, s, q;

vector<Query> queries;
vector<int64_t> res; 

ii dp[11][11][2];
int d[11], sz, pow10[11];
bool mark[11][11][2];

ii calc(int id, int mod, bool checked,  bool tight) {
	if (id < 0) {
		if (mod == 0 || checked) {
			return {1, 0LL};
		}
		return {0, 0LL};
	}

	ii &res = dp[id][mod][checked];
	if (!tight && mark[id][mod][checked]) return res; 

	ii cur = {0, 0LL};

	int max_digt = tight ? d[id] : 9;
	FOR(i, 0, max_digt) {
		ii next_state = calc(id - 1, (mod * 10 + i) % s, checked || i == s, tight && (i == max_digt)); 
		cur.fi += next_state.fi;
		cur.se += next_state.se + 1ll * i * pow10[id] * next_state.fi; 
	}

	if (!tight) {
		mark[id][mod][checked] = true;
		res = cur; 
	}
	return cur; 
}

ii solve(int x) {
	sz = 0;
	while (x) {
		d[sz] = x % 10;
		x /= 10;
		sz++;
	}
	return calc(sz - 1, 0, 0, true);
}


bool check(int64_t x) {
	if (x % s == 0) return true;
	while (x) {
		if (x % 10 == s) return true;
		x /= 10;
	}
	return false;
}

int64_t sum(int x) {
	return 1ll * x * (x + 1) / 2; 
}

int64_t st[4 * MAXN];

void update(int id, int l, int r, int pos, int64_t val) {
	if (l > pos || pos > r) return ;
	if (l == r) {
		st[id] = val;
		return ;
	}
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	st[id] = st[id << 1] + st[id << 1 | 1];
}

int64_t Get(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return 0LL;
	if (u <= l && r <= v) return st[id];
	int mid = (l + r) >> 1;
	return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}

void process(void) {
	cin >> n >> s >> q;
	queries.resize(q);
	FOR(i, 0, q - 1) {
		queries[i].Read(i);
		if (queries[i].type == 1) {
			zip.add(queries[i].a);
		}
	}
	
	zip.Compress();
	int _n = size(zip.z) + 4;

	for (Query &x : queries) {
		if (x.type == 2) {
			int64_t res = sum(x.b) - sum(x.a - 1);
			res += solve(x.b).se - solve(x.a - 1).se;
			int idxL = zip.get(x.a);
			int idxR = upper_bound(all(zip.z), x.b) - zip.z.begin();
			res += Get(1, 1, _n, idxL, idxR);
			cout << res << el;
		} else {
			if (check(x.a)) {
				update(1, 1, _n, zip.get(x.a), 2 * x.b - 2 * x.a);
			} else update(1, 1, _n, zip.get(x.a), x.b - x.a);
		}
	}
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "sdseq"
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin); 
		freopen(name".out", "w", stdout);
	}
	//____________________________________________________
	pow10[0] = 1;
	FOR(i, 1, 9) pow10[i] = pow10[i - 1] * 10;
	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
	return 0;
}
