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

#define name "O"

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

const int MAXN = 1e6 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

int L, R, n;
ii range[MAXN];
multiset<int> lower, upper; 

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> L >> R >> n;
    
    FOR(i, 1, 1e6) range[i] = {-1, -1};

    int cnt = 0;
    while (n--) {
        char op;
        cin >> op;
        if (op == '+') {
            int idx, s, t; 
            cin >> idx >> s >> t; 
            range[idx] = {s, t};
            if (s <= L && R <= t) {
                cnt++;
            } else if (s <= L) {
                lower.insert(t);
            } else if (R <= t) {
                upper.insert(s);
            }
            
        } else {
            int idx; cin >> idx; 
            if (range[idx].fi <= L && range[idx].se >= R) cnt--;
            else if (range[idx].fi <= L) {
                lower.erase(lower.find(range[idx].se));
            } else if (range[idx].se >= R) {
                upper.erase(upper.find(range[idx].fi));
            }
            range[idx] = {-1, -1};
        }

        if (cnt > 0) {
            cout << 1;
        } else if (!lower.empty() && !upper.empty() && *lower.rbegin() >= *upper.begin())  {
            cout << 2;
        } else cout << -1;
        cout << el;
    }

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
