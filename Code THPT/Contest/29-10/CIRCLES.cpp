/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho with luv <3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1011;

struct Circle {
	int x, y, r; 
	
	Circle() {
		x = y = r = 0;
	}

	friend istream &operator >>(istream &in, Circle &a) {
		in >> a.x >> a.y >> a.r;
		return in;
	}
} circles[MAXN];

int n; 


void run_case(void) {
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> circles[i];
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("CIRCLES.inp", "r", stdin);
	freopen("CIRCLES.out", "w", stdout);

	int tests = 1;
	// cin >> tests;
	while (tests--) run_case();
	// cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s Tinh nop";
}
