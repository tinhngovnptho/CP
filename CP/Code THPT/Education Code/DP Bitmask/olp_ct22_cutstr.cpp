#include<bits/stdc++.h>

using namespace std;
bool f[10001][10001],check[10001];
string s;
void init()
{
    memset(f, false, sizeof(f));
    memset(check, false, sizeof(check));
    check[1]=true;

    getline(cin, s);
    long n= (int)s.size();
    for(int i=0; i<(int)n; i++) f[i][i]=true;
    for(int k=2; k<=(int)n; k++)
    {
        for(int i=0; i<n-k+1; i++)
        {
            long j=i+k-1;
            if(k==2 && s[i]==s[j]) f[i][j]=true;
            else f[i][j]=f[i+1][j-1] && (s[i]==s[j]);
            if(f[i][j])
            {
                check[k]=true;
            }
        }
    }

}

vector<vector<int>> dp;
vector<int> len;
int k;

void maximize(int &a, int b)
{
    if (a < b) a = b;
}

int calc(int i, int j)
{
    if(j == k) return 1;
    if (i > s.size())
    {
        return j == k;
    }

    if (~dp[i][j]) return dp[i][j];

    int res = 0;
    maximize(res, dp[i + 1][j]);
    if (f[i][i + len[j] - 1]) maximize(res, calc(i + len[j], j + 1));

    return dp[i][j] = res;
}
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    init();
    long q;
    cin>>q;
    string res[q];
    for(int i=0; i<q; i++)
    {
        bool kt=true;
        cin >> k;
        len.resize(k);
        int cc = 0;
        for(int j= 0; j < k; j++)
        {
            cin >> len[j];
            if(!check[len[j]])
            {
                kt=false;
            }
            cc += len[j];
        }
        if(kt && cc <= s.size())
        {
//				for (int _i = 0; _i <= 100; ++_i){
//				dp.assign(s.size() + 2, vector<int>(k + 2, -1));
//					if (calc(0, 0)) {
//						res[i]="YES";
//						break;
//					}
//					shuffle(len.begin(), len.end(), rng);
//				}
            if(res[i] == "") res[i] = "YES";
        }
        else res[i]="NO";
    }
    for(int i=0; i<q; i++) cout<<res[i]<<endl;
}
