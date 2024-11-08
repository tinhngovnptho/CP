// author : nhatanh_k7
#include <bits/stdc++.h>





using namespace std;


#define file(name)  if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second




template <class X, class Y> bool maximize(X &a, const Y &b){if(a < b) return a = b, true;return false;}
template <class X, class Y> bool minimize(X &a, const Y &b){if(a > b) return a = b, true;return false;}




ll n;
ll b[300005];
ll a[300005];
ll cnt[300005];
ll f[300005][33];
ll dp[300005];
ll solve(ll l,ll r){
    //cout << l << ' ' << r << endl;
    if (!a[l]) return 1;
    f[l][cnt[l]] = l - 1;
    for(int i=l+1;i<=r;i++)
    {
        int M = cnt[i],pos = i-1;
        while(1)
        {
            f[i][M]=pos;
            if(pos<l||(!(~f[pos][M]))) break;
            pos=f[pos][M]; M++;
        }
    }
    dp[l-1]=0;
    for(int i=l;i<=r;i++)
    {
        for(int j=0;j<=30;j++) if(~f[i][j]) dp[i]=min(dp[i],dp[f[i][j]]+1);
    }
    return dp[r];
}
void process(){
    cin >> n;
    for (int i = 1;i <= n;++i){
        cin >> b[i];
    }
    for(int i=0;i<=n;i++) dp[i]=1e18, cnt[i] = 0;
    for(int i=0;i<=n;i++) for(int j=0;j<=30;j++) f[i][j]=-1;
    for (int i = 1;i < n;++i){
        a[i] = b[i + 1] - b[i];
        while(((a[i] % 2 == 0))&&a[i]) a[i] /= 2,cnt[i]++;
    }
    ll res = 1;
    for (int l = 1, r = 1;l < n;l = r + 1){
        r = l;
        while (r + 1 < n && a[r + 1] == a[r]) ++r;
        res += solve(l, r);
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
      file("delete")


     int test; cin >> test; while (test--)
    process();




    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
   return 0;
}
