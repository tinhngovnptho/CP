#include <bits/stdc++.h>

#define TASK ""

using namespace std;

using i64 = long long;

const int maxN = 1e5 + 5; 
const int mod = 1e9 + 7; 

int n, q; 
int a[maxN];

struct Node {
	int val, mul, add; 

	Node(int _val = 0, int _mul = 1, int _add = 0) : val(_val), mul(_mul), add(_add) {}

	Node operator + (const Node& other) const {
		Node ret; 
		ret.val = (val + other.val) % mod;
		return ret;  
	}
};

Node st[4 * maxN]; 

void build(int id, int l, int r) {
	if (l == r) {
		st[id].val = a[l];
		st[id].mul = 1; 
		st[id].add = 0;
		return ; 
	}

	if (l > v || r < u) {
		
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> q; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	while (q--) {
		int type, l, r, x; 
		cin >> type >> l >> r; 

		if (type == 1) {
			cin >> x; 
		
		} else if (type == 2) {
			cin >> x; 

		} else if (type == 3) {
			cin >> x; 

		} else {

		}
	}
}