#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define ALL(v) (v).begin(), (v).end()

struct Piece {
    int x, y;
    char type;

    Piece(int _x = 0, int _y = 0, char _type = 0) {
        x = _x; y = _y; type = _type;
    }

    bool operator < (const Piece &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
};

int n, kx, ky;
Piece king;
vector<Piece> row, col, add, sub;

bool check(vector<Piece> &v, char ex) {
    if (v.empty()) return false;
    sort(ALL(v));

    int id = lower_bound(ALL(v), king) - v.begin();
    if (id < (int)v.size() && v[id].type != ex) return true;
    if (id > 0 && v[id - 1].type != ex) return true;
    return false;
}

bool process(void) {
    scanf("%d", &n);
    if (n < 0) exit(EXIT_SUCCESS);

    scanf("%d%d", &kx, &ky);
    row.clear();
    col.clear();
    add.clear();
    sub.clear();

    REP(gspvhcute, n) {
        int x, y; char t[5];
        scanf("%s%d%d", t, &x, &y);
        Piece p(x, y, t[0]);
        if (x == kx) row.push_back(p);
        if (y == ky) col.push_back(p);
        if (x + y == kx + ky) add.push_back(p);
        if (x - y == kx - ky) sub.push_back(p);
    }

    king = Piece(kx, ky, 'K');
    if (check(row, 'B')) return true;
    if (check(col, 'B')) return true;
    if (check(add, 'R')) return true;
    if (check(sub, 'R')) return true;
    return false;
}

int main(void) {
    freopen("check.inp", "r", stdin);
    freopen("check.out", "w", stdout);

    while (true) printf("%s\n", process() ? "YES" : "NO");
    return 0;
}