// Author: tinhnopro (ngh)
#include <bits/stdc++.h>

using namespace std;

#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()
#define szv(v) ((int)(v).size())
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

#define name "gratitude"

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;

template <class X, class Y>
bool maximize(X &a, Y b)
{
    return a < b ? a = b, 1 : 0;
}

template <class X, class Y>
bool minimize(X &a, Y b)
{
    return a > b ? a = b, 1 : 0;
}

template <class T>
using vector2d = vector<vector<T>>;

// const int MAXN = 5e5 + 11; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7;
// const int INF = 1e9 + 11;
// const ll INFF = 1e18 + 11;

int n, k;
unordered_map<string, int> cnt, pos;
vector<string> v, v2;
string s;

bool cmp(const ii &a, const ii &b)
{
    if (a.fi == b.fi)
    {
        return a.se > b.se;
    }
    return a.fi > b.fi;
}

void solve(void)
{
    cin >> n >> k;
    cin.ignore();
    FOR(i, 1, 3 * n)
    {
        getline(cin, s);
        cnt[s]++;
        pos[s] = i;
        v.push_back(s);
        v2.push_back(s);
    }

    sort(all(v));
    v.resize(distance(v.begin(), unique(all(v))));

    vector<ii> d;
    FOR(i, 0, szv(v) - 1)
    d.push_back({cnt[v[i]], pos[v[i]]});

    sort(all(d), cmp);

    FOR(i, 0, min(k - 1, szv(d) - 1))
    {
        int id = d[i].se;
        cout << v2[id - 1] << el;
    }
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    //___________________________________
    // int t; cin >> t; while (t--)
    solve();

    cerr << "Runtime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
