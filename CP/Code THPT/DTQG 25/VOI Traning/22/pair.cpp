/*
    Author: Tinhnopro (Tinh nop)
    From: CHV Phu Tho
    MLE
 */
#include<bits/stdc++.h>

namespace std {
    // optimize min max
    template<typename T1, typename T2> bool maximize(T1 &a, T2 b) { return a < b ? a = b, 1 : 0; }
    template<typename T1, typename T2> bool minimize(T1 &a, T2 b) { return a > b ? a = b, 1 : 0; }
    // vector
    template<typename T, int D> struct vec : public vector<vec<T, D - 1>> {
        static_assert(D >= 1, "Init error");
        template<typename... Args>
            vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
    };
    template<typename T> struct vec<T, 1> : public vector<T> {
        vec(int n = 0, T val = T()) : vector<T>(n, val) {}
        template<typename InputIt>
            vec(InputIt first, InputIt last) : vector<T>(first, last) {}
    };
    // size
    template<typename T> int Size(const T &a) {  return a.size(); }
}
using namespace std;

const int MAXN = 2009;

int n, d, a[MAXN];

struct Data {
    int sum, i, j;

    Data() {
        sum = i = j = 0;
    }

    Data(int _sum, int _i, int _j) {
        sum = _sum; i = _i; j = _j;
    }
};

vec<Data, 1> v;

bool cmp(const Data &x, const Data &y) {
    if (x.sum == y.sum) {
        if (x.i == y.i) {
            return x.j > y.j;
        }
        return x.i < y.i;
    }
    return x.sum < y.sum;
}

void process(void) {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            v.emplace_back(a[i] + a[j], i, j);
        }
    }
    sort(v.begin(), v.end(), cmp);

    for (Data &x : v) {
        cout << x.sum << " " << x.i << " " << x.j << '\n';
    }
}

int32_t main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    #define name "pair"
    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }

    // int t; cin >> t; while (t--)
    process();

    cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. Code by Tinhnopro\n";
    return 0;
}
