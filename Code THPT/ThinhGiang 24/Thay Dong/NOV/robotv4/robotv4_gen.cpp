/*
	Author: Tinhnopro (a.k.a Tinh nop)
	From: CHV Phu Tho
 */
#include <bits/stdc++.h>

#define name "robotv4"

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int64_t randInt(int64_t l, int64_t r) {
	return uniform_int_distribution<int64_t> (l, r) (rng);
}

char randaz(void) {
	return char('a' + randInt(0, 25));
}

char randAZ(void) {
	return char('A' + randInt(0, 25));
}

int main(void) {
	for (int test = 1; test <= 100; ++test) {
		ofstream cout(name".inp");

		int n = randInt(1, 10);
		cout << n << '\n';
		for (int i = 1; i <= 2 * n + 1; ++i) {
			cout << randInt(1, 10) << ' ';
		}

		cout.close();

		system(name".exe");
		system(name"_bf.exe");
		if (system("fc " name ".out " name ".ans") != 0) {
			cerr << "WA";
			return 0;
		}
	}
	return 0;
}
