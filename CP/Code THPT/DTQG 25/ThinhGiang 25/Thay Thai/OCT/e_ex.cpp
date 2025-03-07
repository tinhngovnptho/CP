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

const int N = 45;
int n;
ll k;
ll dp[N][2];

ll sol(int i, int last){
    if (i == n + 1)
        return 1;
    if (~dp[i][last])
        return dp[i][last];

    ll cur = 0;

    if (!last)
        cur += sol(i + 1, 1);
    if (cur > k)
        cur = k +  1;

    cur += sol(i + 1, 0);
    if (cur > k)
        cur = k + 1;

    return dp[i][last] = cur;
}

void Trace(int i, int last){
    if (i == n + 1)
        return;

    if (!last && sol(i + 1, 0) < k){
        k -= sol(i + 1, 0);
        cout << 1;
        Trace(i + 1, 1);
        return;
    }
    else{
        cout << 0;
        Trace(i + 1, 0);
    }
}

void SOLVE(){
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));

    if (sol(1, 0) < k){
        cout << -1;
        return;
    }

    Trace(1, 0);
}

signed main(){
    Faster
    openfile("KBIN")

    int q = 1;

//    cin >> q;

    while (q --){
        SOLVE();
    }

    return 0;
}
