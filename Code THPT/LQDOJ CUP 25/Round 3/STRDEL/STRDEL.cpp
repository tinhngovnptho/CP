#include<bits/stdc++.h>

// Author: Tinhnopro (a.k.a NVT)

using namespace std;

#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define ld long double
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(v) (int) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define MASK(x) (1LL << (x))
#define ONBIT(i, mask) (mask | MASK(i))
#define OFFBIT(i, mask) mask & ~(MASK(i))

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

const int MAXN = 1e5 + 11;

int n, k;
char s[MAXN];
int rar[MAXN];

void process(void) {
	cin >> n >> k;
	FOR(i, 1, n) cin >> s[i];
	int i = 1, res = 1;
	while (i <= n) {
		rar[res]++;
		int j = i + 1; 
		while (j <= n && s[j] == s[i]) {
			rar[res]++;
			j++;
		}
		i = j;
		res++;
	}
	priority_queue<int> pq;
	FOR(i, 1, res - 1) pq.push(rar[i]);
	while (!pq.empty()) {
		int d = pq.top();
		// cerr << d << el;
		pq.pop();
		d--;
		pq.push(d);
		k--;
		if (k == 0) break;
	}
	ll ans = 0;
	while (!pq.empty()) {
		int d = pq.top();
		ans += 1LL * d * (d + 1) / 2;
		pq.pop();
	}
	cout << ans;
}

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#define Task "STRDEL"
	if (fopen(Task".inp", "r")) {
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}

	// int t; cin >> t; while (t--)
	process();

	return 0;
}
