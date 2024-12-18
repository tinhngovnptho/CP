#include <bits/stdc++.h>

#define TASK "dd"

using namespace std;

using i64 = long long;


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".ans", "w", stdout);
	}

	int a, b; 
	cin >> a >> b; 
	cout << (a + b);
}