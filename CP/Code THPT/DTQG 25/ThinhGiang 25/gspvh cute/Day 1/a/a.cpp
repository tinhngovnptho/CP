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

#define name "color"

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

// const int MAXN = 1e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

string color[6] = {"Red", "Purple", "Blue", "Green", "Yellow", "Orange"};

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    string s1, s2;
    cin >> s1 >> s2; 

    int idx1 = -1, idx2 = -1;

    REP(i, 0, 6) {
        if (idx1 == -1 && color[i] == s1) idx1 = i;
        if (idx2 == -1 && color[i] == s2) idx2 = i;
    }

    if (idx1 == -1 || idx2 == -1) {
        cout << "None";
        return 0;
    }

    if (idx1 > idx2) swap(idx1, idx2);

    if (idx2 == idx1) {
        cout << "Same";
    } else if (idx2 - idx1 == 1 || idx2 - idx1 == 5) {
        cout << "Adjacent";
    } else if (idx2 - idx1 == 2 || idx2 - idx1 == 4) {
        if (idx2 - idx1 == 4) swap(idx1, idx2);
        if (idx1 + 1 < 6) cout << color[idx1 + 1];
        else cout << color[0];
    } else if (idx2 - idx1 == 3) {
        cout << "Complementary";
    } else {
        cout << "None";
    }

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
