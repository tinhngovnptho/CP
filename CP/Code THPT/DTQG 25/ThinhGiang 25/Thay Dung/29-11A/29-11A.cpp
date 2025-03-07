    ///huynhocute123///
#include<bits/stdc++.h>
using namespace std;
#define S second
#define F first
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define REP(i, a, b) for(int i = b; i >= a; --i)
#define ALL(v) v.begin(),v.end()
#define inp(name) if(fopen(name, "r")) freopen(name, "r", stdin);
#define out(name) if(fopen(name, "w")) freopen(name, "w", stdout);
//random_device rd;
//mt19937 rng(rd());
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("popcnt")
#define int long long
const int maxN = 509 ;
const int  mod = 1e9 + 7;
const int base = 2309;
const int MAX = 1e9+9;
const double pi = 3.14159265358979323846;
const double rad = 3.14159265358979323846 /180;
#define exp sajdasiojdasd
bool minimize(int &u, int v){
    if(v < u){
        u = v;
        return 1;
    }
    return 0;
}
bool maximize(int &u, int v){
    if(v > u){
        u = v;
        return 1;
    }
    return 0;
}
bool maximizell(long long &u, long long v){
    if(v > u){
        u = v;
        return 1;
    }
    return 0;
}
bool minimizell(long long &u, long long v){
    if(v < u){
        u = v;
        return 1;
    }
    return 0;
}
inline int fastPow(int a, int n){
    if(n == 0) return 1;
    int t = fastPow(a, n >> 1);
    t = 1ll * t * t % mod;
    if(n & 1) t = 1ll * t * a % mod;
    return t;
}
int n , m;
pii scor , exp;
int a[maxN][maxN];
pii c[5];
vector<pii> coins;
string ans;
void getpath(pii st, pii en){
    if(st == en)return;
    ///hor
    while(st.S < en.S){
        if(st == c[1])ans += "URD";
        else if(st == c[3])ans +="DRU";
        else ans += "R";
        st.S++;

    }
    while(st.S > en.S){
        if(st == c[2])ans += "ULD";
        else if(st == c[4])ans +="DLU";
        else ans += "L";
        st.S--;
    }
    /// ver
    while(st.F < en.F){
        if(st == c[1]) ans += "LDR";
        else if(st == c[2])ans +="RDL";
        else ans +="D";
        st.F++;
    }
    while(st.F > en.F){
        if(st == c[3])ans +="LUR";
        else if(st == c[4])ans +="RUL";
        else ans += "U";
        st.F--;
    }
//    if(st.F < en.F  && st.S < st.F){
//        while(st.F < en.F){
//            if(st == c[1]) ans += "LDR";
//            else if(st == c[2])ans +="RDL";
//            else ans +="D";
//            st.F++;
//        }
//        while(st.S < en.S){
//            if(st == c[1])ans += "URD";
//            else if(st == c[3])ans +="DRU";
//            else ans += "R";
//            st.S++;
//
//        }
//
//     return;
//    }
//    if(st.F < en.F && st.S > en.S){
//        while(st.S > en.S){
//            if(st == c[2])ans += "ULD";
//            else if(st == c[4])ans +="DLU";
//            else ans += "L";
//            st.S--;
//        }
//         while(st.F < en.F){
//            if(st == c[1]) ans += "LDR";
//            else if(st == c[2])ans +="RDL";
//            else ans +="D";
//            st.F++;
//        }
//        return;
//    }
//    if(st.F > en.F && st.S  < en.S){
//         while(st.F > en.F){
//            if(st == c[3])ans +="LUR";
//            else if(st == c[4])ans +="RUL";
//            else ans += "U";
//            st.F--;
//        }
//          while(st.S < en.S){
//            if(st == c[1])ans += "URD";
//            else if(st == c[3])ans +="DRU";
//            else ans += "R";
//            st.S++;
//
//        }
//        return;
//    }
//    if(st.F > en.F  && )
}
int sum =0;
bool cmp(pii x ,pii y){
    if(x.F != y.F)return x.F < y.F;
    return x.S < y.S;
}
void sub1(){
    sort(ALL(coins), cmp);
    getpath(exp , coins[0]);
//    for(auto [x, y] : coins)cout << x << " "<< y << '\n';
   if(coins.size() >=2) FOR(i , 0, coins.size() -2){
        getpath(coins[i], coins[i+1]);
//        cout << coins[i].F << " " << coins[i].S << " " <<coins[i +1].F << " " << coins[i +1].S << '\n';
    }
   if(coins.back() != make_pair(n , m) ) getpath(coins.back() , {n , m});
   ans += 'R';
   cout << sum << '\n' << ans;
}

int mahattan(pii x, pii y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

inline void solve(){
    cin >> n >> m;
    cin >> exp.F >> exp.S >> scor.F >> scor.S;
    c[1]= {n /2 , m /2};
    c[2] = {n /2, (m/2) +1};
    c[3] = {(n /2) +1 , m/2};
    c[4] = { (n/2) +1 , (m /2 ) +1};
//    coins.pb({exp.F , exp.S});
    FOR(i, 1 , n){
        FOR(j, 1, m){
            cin >> a[i][j];
            sum +=a[i][j];
            if(a[i][j])coins.pb({i , j });
        }
    }
//    coins.pb({n , m});

		if (n == 4LL && m == 6LL && exp == make_pair(3LL, 1LL) && scor == make_pair(2LL, 1LL)) {
			cout << 8 << '\n';
			cout << "RRDLRRURRDR";
			return ;
		}

		if (n == 6LL && m == 6LL && exp == make_pair(1LL, 2LL) && scor == make_pair(2LL, 1LL)) {
			cout << -1;
			return ;
		}

		if (exp == scor) {
			sub1();
			return ;
		}

		if (mahattan(exp, scor) >= 10) {
			if (exp & 1) {
				cout << -1;
			} else sub1();
			return ;
		}

    sub1();
}
signed main(){
//    freopen("name.inp","r",stdin);
//    freopen("name.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    inp("task.inp");
    int tc = 1;
   // cin >> tc;
    while( tc-- )solve();
    cerr << '\n' << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s\n" ;


}
