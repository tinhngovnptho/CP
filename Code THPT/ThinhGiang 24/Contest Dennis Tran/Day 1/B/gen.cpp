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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution<int> (l, r) (rng);
}

void process(void) {
    srand(time(nullptr));
    ofstream out("B.inp");
    int n = 400;
    out << n << el;
    out << 1 << el;
    FOR(i, 2, n) {
        if (i > 41) {
            out << i % 40 + 1 << el;
            continue;
        }
        out << i - 1 << el;
    }
    out.close();
    system("B.exe");
    system("B_brute.exe");
    if (system("fc B.out B_brute.out") != 0) {
        exit(0);
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t; while (t--)
    process();


    return 0;
}
