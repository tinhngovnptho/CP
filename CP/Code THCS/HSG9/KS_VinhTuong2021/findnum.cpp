// @author: tinhnopro
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORDE(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }
template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }

/// END OF TEMPLATE

struct Data {
	int sumDigt, modD;
	string value;
};

const int MAXS = 5011, MAXD = 507;

int d, s;
bool visited[MAXS][MAXD];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	file("findnum");
	cin >> d >> s;

	queue<Data> q;
	q.push({0, 0, ""}); visited[0][0] = 1;

	while(!q.empty()) {
		Data t = q.front(); q.pop();
		if (t.sumDigt == s && t.modD == 0) {
			cout << t.value;
			exit(0);
		}
		if (t.sumDigt > s) continue;
		Data tmp;
		FOR(i, 0, 10) {
			tmp.sumDigt = t.sumDigt + i;
			tmp.modD = (t.modD * 10 + i) % d;
			if(visited[tmp.sumDigt][tmp.modD]) continue;
			visited[tmp.sumDigt][tmp.modD] = 1;
			tmp.value = t.value + char(i + '0');
			q.push(tmp);
		}
	}

	cout << -1;

	return 0;
}
