#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}

#define NAME "grandelection"

int main(void) {
    FOR(test, 1, 100){
        ofstream inp(NAME".inp");
        int n = randInt(2, 10);
        inp << n << endl;
        FOR(i, 2, n) {
            inp << randInt(1, i - 1) << " ";
        }
        inp << endl;
        FOR(i, 1, n) {
            inp << randInt(1, 50) << " " << randInt(1, 50) << endl;
        }
        system(NAME".exe");
        system(NAME"_brute.exe");
        if (system("fc " NAME ".out " NAME "_d.out") != 0) {
            break;
        }
    }
}
