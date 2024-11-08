/*
    Author : vuongkm a.k.a kzhi
    K41 IT CHV
*/
#include <bits/stdc++.h>
using namespace std;


//#define int long long
#define ll long long
#define FOR(i,a,b) for (int i = a ; i <= b; ++ i)
#define FOD(i,a,b) for (int i = a; i >= b; -- i)


#define BIT(mask,i)       ((mask >> i) & 1)
#define MASK(i)                (1ll << (i))
#define OFFBIT(mask,i)  (mask &~(1ll<<(i)))
#define ONBIT(mask,i) (mask | (1ll << (i)))
#define lg2(x)    (63 - __builtin_clzll(x))
#define c_bit          __builtin_popcountll

#define vi vector < int >
#define pb push_back
#define all(a) a.begin(),a.end()

#define ii pair<int,int>
#define fi first
#define se second

#define openfile(TASK) if (fopen(TASK".inp","r"))\
        {freopen(TASK".inp","r",stdin);freopen(TASK".out","w",stdout);}
#define endl '\n'
#define Faster ios_base::sync_with_stdio(false); \
                        cin.tie(0);  cout.tie(0);

#define mid(l,r) ((l + r) >> 1)
#define left(id) (id << 1)
#define right(id) ((id << 1) | 1)
#define ci const int

const int N = 1e5 + 5;
const int LOG = 31;

int n, a[N], f[N];
bool c[N];

unordered_map < int, int > d;

struct Data{
    int dau, pos, val;
};

bool cmp(Data A, Data B){
    return A.pos < B.pos;
}

vector < Data > v;

struct RMQ{
    static const int LG = lg2(N);
    int m[LG + 1][N];

    void Build(){
        FOR (i, 1, n)
            m[0][i] = a[i];
        FOR (j, 1, LG)
            for (int i = 1; i + MASK(j) - 1 <= n; i ++)
                m[j][i] = (m[j - 1][i] & m[j - 1][i + MASK(j - 1)]);
    }

    int Get(int l, int r){
        if (l == r)
            return a[l];

        int lk = lg2(r - l + 1);

        return (m[lk][l] & m[lk][r - MASK(lk) + 1]);
    }
} kmv;

int cnp(int i, int l){
    int L = l - 1, R = n + 1;

    while (L + 1 < R){
        int mid = mid(L, R);
        if (kmv.Get(i, mid) == kmv.Get(i, l))
            L = mid;
        else
            R = mid;
    }

    return L;
}

void SOLVE(){
    cin >> n;
    FOR (i, 1, n)
        cin >> a[i];
    f[0] = 0;

    FOR (i, 1, n)
        f[i] = (f[i - 1] ^ a[i]);

    kmv.Build();

    FOR (i, 1, n){
        int j = i;
        while (j <= n){
            int far = cnp(i, j);
            int val = kmv.Get(i, j);
            val ^= f[i - 1]; 
            v.pb({-1, j - 1, val});
            v.pb({1, far, val});
            j = far + 1;
        }
    }

    sort(all(v), cmp);

    ll ans = 0;

    for (auto i : v){
        if (!c[i.pos]){
            c[i.pos] = 1;
            d[f[i.pos]] ++;
        }
        ans += 1ll * i.dau * d[i.val];
    }

    cout << ans;
}

signed main(){
    Faster
    openfile("XONDCNT")

    int q = 1;

//    cin >> q;

    while (q --){
        SOLVE();
    }

    return 0;
}
