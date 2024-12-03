/*
    Author : vuongkm a.k.a kzhi
    K41 IT CHV
*/
#include <bits/stdc++.h>
using namespace std;


#define int long long
#define FOR(i,a,b) for (int i = a ; i <= b; ++ i)
#define FOD(i,a,b) for (int i = a; i >= b; -- i)
#define ONBIT(mask,i) (mask  (1ll << (i)))
#define OFFBIT(mask,i) (mask &~(1ll<<(i)))
#define BIT(mask,i) (mask & (1ll << (i)))
#define MASK(i) (1ll << (i))
#define demll __builtin_popcountll
#define pb push_back
#define ii pair<int,int>
#define fi first
#define se second
#define openfile(TASK) if (fopen(TASK".inp","r")){freopen(TASK".inp","r",stdin);freopen(TASK".out","w",stdout);}
#define endl '\n'
#define Faster ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
#define mid(l,r) ((l + r) >> 1)
#define left(id) (id << 1)
#define right(id) ((id << 1) | 1)

const int maxN = 5e5 + 5;
const int oo = 1e18 + 7;
const int MOD = 1e9 + 7;
const int LOG = 65;
const int base = 311;
const int N = 11;

int n, a[N][N];
int x[maxN], y[maxN];
int cnt[3];

int mex(int A, int B){
    if (A && B)
        return 0;
    if ((A + B) % 2 == 0)
        return 1;
    return 2;
}

namespace Trau{
    void SOLVE(){
        FOR (i, 1, n)
            a[1][i] = x[i];
        FOR (i, 2, n)
            a[i][1] = y[i];

        FOR (i, 2, n)
            FOR (j, 2, n)
                a[i][j] = mex(a[i - 1][j], a[i][j - 1]);

        FOR (i, 1, n)
            FOR (j, 1, n)
                cnt[a[i][j]] ++;

        cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
    }
}

namespace FULL{
    int b[N][maxN], c[maxN][N];

    void SOLVE(){
        memset(cnt, 0, sizeof(cnt));

        FOR (i, 1, n)
            b[1][i] = x[i];
        FOR (i, 1, 5)
            c[1][i] = x[i];

        FOR (i, 2, 5)
            b[i][1] = y[i];
        FOR (i, 2, n)
            c[i][1] = y[i];

        FOR (i, 2, 5)
            FOR (j, 2, n)
                b[i][j] = mex(b[i - 1][j], b[i][j - 1]);

        FOR (i, 2, n)
            FOR (j, 2, 5)
                c[i][j] = mex(c[i - 1][j], c[i][j - 1]);

        FOR (i, 1, n)
            FOR (j, 1, 4)
                cnt[c[i][j]] ++;


        FOR (i, 1, 4)
            FOR (j, 5, n)
                cnt[b[i][j]] ++;

        FOR (i, 5, n){
            int x = b[5][i];
            cnt[x] += n - i + 1;
        }

        FOR (i, 6, n){
            int x = c[i][5];
            cnt[x] += n - i + 1;
        }
        cout << cnt[0] << " " << cnt[1] << " " << cnt[2];
    }
}

void SOLVE(){
    cin >> n;
    FOR (i, 1, n)
        cin >> x[i];

    FOR (i, 2, n)
        cin >> y[i];

    if (n <= 5){
        Trau :: SOLVE();
        return;
    }
    else
        FULL :: SOLVE();
}

signed main()
{
    Faster

    openfile("mex")

    int q = 1;

//    cin >> q;

    while (q --){
        SOLVE();
    }

    return 0;
}