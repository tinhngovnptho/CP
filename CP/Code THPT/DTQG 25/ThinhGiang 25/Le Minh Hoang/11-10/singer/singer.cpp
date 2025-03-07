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

#define name "singer"

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

const int MAXN = 1e5 + 11;
// const int MOD = 1e9 + 7; 
// const ll INFF = 1e18 + 11; 

struct Fraq {
    int l, r, k, id; 
    Fraq() {
        l = r = 0;
    }
} singer[MAXN], song[MAXN];

int n, m;
multiset<ii> s;
int res[MAXN];

bool cmp(const Fraq &a, const Fraq &b) {
    if (a.r == b.r) {
        return a.l < b.l;
    }
    return a.r < b.r;
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //___________________________________
    cin >> n;
    FOR(i, 1, n) {
        cin >> song[i].l >> song[i].r;
        song[i].k = i;
    }
    cin >> m;
    FOR(i, 1, m) {
        cin >> singer[i].l >> singer[i].r >> singer[i].k;
        singer[i].id = i;
    }

    sort(singer + 1, singer + m + 1, cmp);
    sort(song + 1, song + n + 1, cmp);

    int i = 1;

    FOR(j, 1, m) {
        while (i <= n && song[i].r <= singer[j].r) {
            s.insert({song[i].l, i});
            ++i;
        }

        while (singer[j].k && !s.empty()) {
            
            auto it = s.lower_bound({singer[j].l, -1e9});
            if (it == s.end()) break;
            res[song[it->second].k] = singer[j].id;
            s.erase(it);
            singer[j].k--;
        }
    }

    FOR(i, 1, n) {
        if (!res[i]) {
            cout << "NO"; 
            return 0;
        }
    }

    cout << "YES\n";
    FOR(i, 1, n) cout << res[i] << " ";

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
