#include <bits/stdc++.h>

using namespace std;

#define Int __int128_t
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<ll, ll>
#define vii vector<pii>
#define bitcnt(n) __builtin_popcount(n)
#define bit(i, n) ((n >> i) & 1)
#define flip(i, n) (n ^ (1 << i))
#define minbit(n) (n & (-n))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b
#define pb push_back
#define pob pop_back
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);}
#define fi first
#define se second
#define HuyDepTraiVl ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int maxn = 1e7 + 5;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;
int n, ans = -1, a[maxn];
ll s, cur = 0;
void mini(int &x, int y) {
    if (x == -1 || x > y) x = y;
}
void readInt(int &n) {
    n = 0;
    int c = getchar();
    for ( ; c > 47 && c < 58; c = getchar()) n = (n << 3) + (n << 1) + c - 48;
}
void readLL(ll &n) {
    n = 0;
    int c = getchar();
    for ( ; c > 47 && c < 58; c = getchar()) n = (n << 3) + (n << 1) + c - 48;
}
int main() {
    HuyDepTraiVl
    file("CAU3");
    readInt(n); readLL(s);
    for (int i = 1; i <= n; ++i) {
        readInt(a[i]);
    }
    int j = 1;
    for (int i = 1; i <= n; ++i) {
        while (j <= n) {
            if (cur >= s) break;
            cur += a[j]; j++;
        }
        //  << cur << ' ';
        if (cur >= s) mini(ans, j - i);
        // cout << i << ' ' << j << '\n';
        cur -= a[i];
    }
    cout << ans;
    return 0;
}
