/*
	Author: Tinhnopro (Tinh nop)
	From: CHV with luv <3
	while (true) coding();
*/
#include<bits/stdc++.h>

#define el '\n'
#define fi first
#define se second

#define all(v) (v).begin(), (v).end()
#define size(v) int((v).size())
#define eb emplace_back

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

#define Mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | Mask(i))
#define offbit(i, mask) (mask & ~(Mask(i)))
#define cntbit(x) __builtin_popcountll(x)
#define Log2(x) (63 - __builtin_clzll(x))

using namespace std;

using db = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;

template<class X, class Y> bool maximize(X &a, Y b) { 
	return a < b ? a = b, 1 : 0; 
}

template<class X, class Y> bool minimize(X &a, Y b) { 
	return a > b ? a = b, 1 : 0; 
}

// const int dx[8] = {+1, -1, +0, +0, +1, -1, +1, -1}, dy[8] = {+0, +0, +1, -1, +1, -1, -1, +1};
// const int INF = 1e9 + 11, MAXN = 5e5 + 11, MOD = 1e9 + 7; 
// const int64_t INFF = (int64_t) 1e18 + 7;
//_______________________________________________________________________________________________

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t randInt(int64_t a, int64_t b) {
    return uniform_int_distribution<int>(a, b) (rng);
}

#define name ""

void gentest(void) {
    ofstream out(name".out");
    

    out.close();
}

int32_t main(void) {

    int test = 100;
    
    while(test--) {
        gentest();
        system(name".exe");
        system(name"_bf.exe");
        if (system("fc "name".out "name".ans") != 0) {
            cout << "WA";
            return 0;
        }
    }

	return 0;
}
