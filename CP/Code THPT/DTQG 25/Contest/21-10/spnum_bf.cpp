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

const int MAX = 1e7 + 1;
const int N = 140;
bool nt[N];
int t[MAX];

ll A, B;
string S;
ll dp[16][N];

void ssnt(int n){
    FOR (i, 2, trunc(sqrt(n)))
        if (!nt[i])
            FOR (j, i, n / i)
                nt[i * j] = 1;
    nt[1] = 1;
}

int tcs(ll X){
    if (X == 0)
        return 0;
    return X % 10 + tcs(X / 10);
}

bool kt(ll X){
    return (!nt[tcs(X)]);
}

void pre(){
    ssnt(139);

    FOR (i, 1, MAX - 1)
        if (kt(1ll * i * i))
            t[i] = 1 + t[i - 1];
        else
            t[i] = t[i - 1];

    memset(dp, -1, sizeof(dp));
}

string numtostr(ll &X){
    string res = "";

    while (X){
        res += char(X % 10 + '0');
        X /= 10;
    }

    while (res.size() < 15)
        res += '0';

    reverse(res.begin(), res.end());

    return res;
}

ll sol(int i, int sum){
    if (i == S.size())
        return (!nt[sum]);

    if (~dp[i][sum])
        return dp[i][sum];

    ll cur = 0;

    FOR (j, 0, 9)
        cur += sol(i + 1, sum + j);

    return dp[i][sum] = cur;
}

ll cal(int i, int sum, bool ok){
    if (i == S.size())
        return (!nt[sum]);

    if (ok)
        return sol(i, sum);

    ll cur = 0;

    int lim = S[i] - '0';

    FOR (j, 0, lim)
        cur += cal(i + 1, sum + j, (j < lim));

    return cur;
}

ll calc(ll &X){
    int id = trunc(sqrt(X));
    S = numtostr(X);

    return cal(0, 0, 0) - t[id];
}

void SOLVE(){
    cin >> A >> B;
    A --;

    cout << calc(B) - calc(A) << '\n';
}

signed main(){
    Faster
    openfile("SPNUM")

    pre();

    int q = 1;

    cin >> q;

    while (q --){
        SOLVE();
    }

    return 0;
}