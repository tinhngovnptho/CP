/**------------------------------------------
------Author: Tinhnopro (Tinh nop) ----------
---------From: CHV with luv <3 --------------
---------Value = Live + Love ---------------- 
------------------------------------------**/
#include<bits/stdc++.h>

#define el '\n'

#define all(v) (v).begin(), (v).end()

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

#define Mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)


using namespace std;

int n, m;
vector<int> v, v1;
int64_t d[1 << 20 + 1], d2[1 << 20 + 1];

void process(void) {
    cin >> n >> m;
    FOR(i, 1, n) {
        int x; cin >> x;
        v.push_back(x);
    }
    FOR(i, 1, n / 2) {
        v1.push_back(v.back());
        v.pop_back();
    }

    reverse(all(v1));

    FOR(mask, 0, Mask(v.size()) - 1)  {
        int64_t res = 0;
        FOR(i, 0, v.size() - 1) if (getbit(i, mask)) {
            res += v[i];
        }
        d[mask] = res;
    }
    FOR(mask, 0, Mask(v1.size()) - 1)  {
        int64_t res = 0;
        FOR(i, 0, v1.size() - 1) if (getbit(i, mask)) {
            res += v1[i];
        }
        d2[mask] = res;
    }

    FOR(mask1, 0, Mask(v.size()) - 1) {
        FOR(mask2, 0, Mask(v1.size()) - 1) {
            if (d[mask1] + d2[mask2] == m) {
                FOR(i, 0, v.size() - 1) cout << getbit(i, mask1);
                FOR(i, 0, v1.size() - 1) cout << getbit(i, mask2);
                return ;
            }
        }
    }

}

int32_t main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    #define name "bai4"
    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin); 
        freopen(name".out", "w", stdout);
    }
    //____________________________________________________
    // int t; cin >> t; while (t--)
    process();

    cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
    return 0;
}
