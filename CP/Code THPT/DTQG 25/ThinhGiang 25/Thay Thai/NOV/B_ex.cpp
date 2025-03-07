/*
    Author : kmv a.k.a kzhi
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
#define vc vector < char >
#define vs vector < string >
#define all(a) a.begin(), a.end()
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

template <class X, class Y> bool maximize(X &a, const Y &b){if(a < b) return a = b, true;return false;}
template <class X, class Y> bool minimize(X &a, const Y &b){if(a >= b) return a = b, true;return false;}

const int N = 1e6 + 5;

int n, m;
vector < vc > v;
vector < vs > f;
vector < vi > c, d;

char dp[N];

int dx[] = {0, -1};
int dy[] = {-1, 0};

int dx2[] = {0, 1};
int dy2[] = {1, 0};

void bfs2(){
    FOR (i, 1, n + m - 1)
        dp[i] = 'z' + 1;

    d[1][1] = 1;
    dp[1] = v[1][1];

    queue < ii > q;
    q.push({1, 1});

    while (q.size()){
        ii val = q.front();
        q.pop();
        int x = val.fi;
        int y = val.se;

        if (v[x][y] != dp[x + y - 1])
            continue;

        FOR (i, 0, 1){
            int nx = x + dx2[i];
            int ny = y + dy2[i];

            if (nx > n || ny > m || !c[nx][ny] || d[nx][ny])
                continue;

            d[nx][ny] = 1;

            if (minimize(dp[nx + ny - 1], v[nx][ny]))
                q.push({nx, ny});
        }
    }
}

void bfs(){
    queue < ii > q;

    q.push({n, m});

    while (q.size()){
        ii val = q.front();
        q.pop();
        int x = val.fi;
        int y = val.se;

        FOR (i, 0, 1){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || v[nx][ny] == '#' || c[nx][ny])
                continue;

            c[nx][ny] = 1;

            q.push({nx, ny});
        }
    }
}

void SOLVE(){
    cin >> n >> m;
    v.assign(n + 1, vc(m + 1));
    FOR (i, 1, n)
        FOR (j, 1, m)
            cin >> v[i][j];

    c.assign(n + 1, vi(m + 1, 0));

    bfs();

    d.assign(n + 1, vi(m + 1, 0));

    bfs2();

    FOR (i, 1, n + m - 2)
        cout << dp[i];
    cout << v[n][m];

}

signed main(){
    Faster
    openfile("MINTRIX")

    int q = 1;

//    cin >> q;

    while (q --){
        SOLVE();
    }

    return 0;
}
