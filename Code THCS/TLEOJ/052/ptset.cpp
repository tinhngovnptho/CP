#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(s) (int)(s).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FORA(it, v) for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout);

typedef long long int64;
typedef unsigned long long uint64;
typedef __int128_t int128;

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

// end of template

const int MAXN = 1e3 + 11;

int n;
pair<int, int> p[MAXN];

double get_a(int i, int j) {
	if (p[i].fi == p[j].fi) return -1e9;
	return (double) (p[i].se - p[j].se) / (p[i].fi - p[j].fi);
}

void process(void) {
	cin >> n;
	FORE(i, 1, n) cin >> p[i].fi >> p[i].se;
	int ans = 0, d = 0;
	double Pa = 0;
	FORE(i, 1, n) if (p[i].fi == 0) ans++;
	unordered_map<double, int> mp;
	FORE(i, 1, n) {
		mp.clear();
		FORE(j, 1, n) if(p[i].fi != p[j].fi) mp[get_a(i, j)]++;
		FORA(it, mp) if (maximize(ans, it->se + 1)) {
			Pa = it->fi;
			d = i;
		}
	}
	vector<pair<int, int> > P;
	if (d == 0) {
		FORE(i, 1, n) if (p[i].fi == 0) P.push_back(p[i]);
	} else {
		FORE(i, 1, n) if (i == d || get_a(d, i) == Pa) P.push_back(p[i]);
	}
//	cout << d << " " << Pa << "\n";
	sort(ALL(P));
	cout << sz(P) << "\n";
	FORA(it, P) cout << it->fi << " " << it->se << "\n";
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	file("ptset");
	int t = 1; // cin >> t;
	while (t--) {
		process();
	}
	return 0;
}

// author: tinhnopro
