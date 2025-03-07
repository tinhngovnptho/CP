#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define ll  long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi  vector<int>
#define fi  first
#define se  second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORX(i, a, b, x) for (int i = (a), _b = (b); i <= _b; i += (x))
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

//const int MAXN = (int) 5e5 + 11;
const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void add(int &a, ll b) {
    ll c = a + b;
    c %= MOD;
    a = c;
}

struct Matrix {
    vector<vi> mat;
    int r, c;

    Matrix(int _r = 0, int _c = 0) {
        r = _r;
        c = _c;
        mat.assign(r, vi(c, 0));
    }
    Matrix(vector<vi> _mat) {
        r = _mat.size();
        c = _mat[0].size();
        mat = _mat;
    }

    Matrix operator *(const Matrix &ot) const {
        Matrix res(r, ot.c);
        FOR(i, 0, r - 1) FOR(j, 0, c - 1) {
            FOR(k, 0, c - 1) add(res.mat[i][j], 1LL * mat[i][k] * ot.mat[k][j]);
        }
        return res;
    }
    Matrix pow(ll b) const {
        Matrix res(r, c), a = *this;
        FOR(i, 0, r - 1) res.mat[i][i] = 1;
        for (; b; b >>= 1LL, a = a * a) if (b & 1LL) res = res * a;
        return res;
    }
};
ll n;

void process(void) {
    cin >> n;
    Matrix base({
        {0, 1},
        {1, 1}
    });
    base = base.pow(n);
    cout << base.mat[0][0] << " " << base.mat[0][1] << " " << base.mat[1][0] << base[1][1];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("errichto_matexp_fibonacci");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
