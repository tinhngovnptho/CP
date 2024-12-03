// Author: tinhnopro (ngh)
#include<bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define all(v) (v).begin(), (v).end()

#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "fixstr"

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, Y b) { 
    return a < b ? a = b, 1 : 0; 
}
template<class X, class Y> bool minimize(X &a, Y b) { 
    return a > b ? a = b, 1 : 0; 
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randInt(int l, int r) {
    return uniform_int_distribution<ll> (l, r) (rng);
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    //___________________________________
    FOR(test, 1, 100) {
        ofstream out(name".inp");

        int n = randInt(2, 20);
        FOR(i, 1, n) {
            int p = randInt(0, 1);
            if (p) out << '(';
            else out << ')';
        }
        out << el;
        int q = randInt(1, 10);
        out << q << el;
        FOR(i, 1, q) {
            int r = randInt(0, 2);
            if (r == 0) {
                out << 'C' << " " << randInt(1, n) << el;
            } else if (r == 1 && i > 2) {
                out << 'U' << " " << randInt(1, i - 1) << el;
            } else {
                out << 'Q' << " ";
                int l = randInt(1, n / 2);
                out << l << " " << randInt(l + 1, n) << el;
            }
        }

        out.close();
        system(name".exe");
        system(name"_bf.exe");
        if (system("fc "name".out "name".ans") != 0) {
            cout << "WA";
            return 0;
        }
    }

    return 0;
}
