#include <bits/stdc++.h>

#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define rep(i,a) for (auto i : a)
#define FOR(i,n) fu(i,0,n-1)
#define REP(i,n) fd(i,n-1,0)

#define SZ(X) ((int)(X).size())
#define fi first
#define se second
#define pb push_back


using namespace std;

void print(int x) {cerr << x;}
void print(long long x) {cerr << x;}
void print(long double x) {cerr << x;}
void print(double x) {cerr << x;}
void print(unsigned long long x) {cerr << x;}
void print(char x) {cerr << x;}
void print(bool x) {cerr << (x ? "True" : "False");}
void print(string x) {cerr << x;}

template <typename T,typename H>
void print(pair<T,H> a) {cerr << "("; print(a.fi); cerr << ','; print(a.se); cerr << ')';}
template <typename T>
void print(T vec) {int cnt=0; cerr << "{"; rep(x,vec) cerr << (cnt++?",":""), print(x); cerr << '}';}

void show() {}
template <typename Head, typename ...Tail>
void show(Head H, Tail ...T)
{
    print(H);
    if (sizeof...(T)) cerr << ", ";
    show(T...);
}
#define debug(X...) cerr << "LINE "  << __LINE__ << " - " <<  "[" << #X << "] = [", show(X), cerr << "]\n"

const char ginp[] = ".INP";
const char gout[] = ".OUT";

typedef long long ll;
typedef long double ld;
typedef pair <int,int> ii;

mt19937 rd(time(NULL));
ll Rand(ll l, ll r) {return l + rd() % (r - l + 1);}

const int N = 2e2 + 5;
const int oo = 1e9 + 7;
const ll inf = 1e18 + 7;
const int MOD = 1e9 + 7;
const double PI = acos(-1);

int n,p;
int c[N],dp[N][N],trace[N][N],sz[N],par[N];
vector <int> ke[N];

void enter()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++)
	{
		int u,v;
		cin >> u >> v;
		ke[u].pb(v); ke[v].pb(u);
	}
}

void dfs(int u)
{
	sz[u] = 1;
	for (int i = 0; i <= p; i++) dp[u][i] = -oo;
	dp[u][1] = c[u];
	for (int v : ke[u])
	{
		if (v == par[u]) continue;
		par[v] = u;
		dfs(v);
		for (int i = sz[u]; i >= 0; --i)
			for (int j = 0; (i + j <= p && j <= sz[v]); ++j)
			if (dp[u][i+j] < dp[u][i] + dp[v][j])
			{
				dp[u][i+j] = dp[u][i] + dp[v][j];
				trace[v][i+j] = j;
			}
		sz[u] += sz[v];
	}
}

void Trace(int u, int p)
{
	REP(i,SZ(ke[u]))
	{
		int v = ke[u][i];
		if (v == par[u]) continue;
		if (trace[v][p])
		{
			cout << v << " " << trace[v][p] << "\n";
			Trace(v,trace[v][p]);
			p -= trace[v][p];
		}
	}
	// cout << u << " ";
}

void solve()
{
	dfs(1);
	int root = 1;
	for (int i = 2; i <= n; i++) if (dp[i][p] > dp[root][p]) root = i;
	Trace(root,p);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ptree.inp","r",stdin);
    freopen("ptree.ans","w",stdout);

    enter();
    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";
    return 0;
}
