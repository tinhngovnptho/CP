//TrungNotChung
#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define BIT(x,i) (1&((x)>>(i)))
#define MASK(x)  (1LL<<(x))
#define CNT(x) __builtin_popcountll(x)
#define task "grandelection"

using namespace std;
const int N = (int)1e5+228;
const int logn = 17;

int n, x[N], v[N], lg[N*2], vis[N], t = 0;
vector<vector<int> > divs;
vector<vector<int> > adj, virAdj;
vector<vector<int> > nodes;
int h[N], euler[N * 2], pos[N], f[N*2][logn], sz;
long long dp[N];

void init() {
    int maxValue = 1e5;
    divs.assign(maxValue + 1, vector<int>());
    nodes.assign(maxValue + 1, vector<int>());
    for (int i = 2; i <= maxValue; ++i) {
        for (int j = i; j <= maxValue; j += i) {
            divs[j].push_back(i);
        }
    }

    for (int i = 0; MASK(i) <= maxValue * 2; ++i) {
        lg[MASK(i)] = i;
    }
    for (int i = 1; i <= maxValue * 2; ++i) {
        lg[i] = max(lg[i], lg[i - 1]);
    }
}

void dfs(int u) {
    euler[++sz] = u;
    pos[u] = sz;
    for (int v : adj[u]) {
        h[v] = h[u] + 1;
        dfs(v);
        euler[++sz] = u;
    }
}

int minNode(int u, int v) {
    return (h[u] < h[v] ? u : v);
}

void buildLca() {
    for (int i = 1; i <= sz; ++i) {
        f[i][0] = euler[i];
    }

    for (int j = 1; MASK(j) <= sz; ++j) {
        for (int i = 1; i + MASK(j) - 1 <= sz; ++i) {
            f[i][j] = minNode(f[i][j - 1], f[i + MASK(j-1)][j - 1]);
        }
    }
}

int getLca(int u, int v) {
    int l = pos[u], r = pos[v];
    if (l > r) {
        swap(l, r);
    }
    int k = lg[r - l + 1];
    return minNode(f[l][k], f[r - MASK(k) + 1][k]);
}

bool cmp(int u, int v) {
    return pos[u] < pos[v];
}

void buildVirtualTree(vector<int> &nodes) {
    int m = (int)nodes.size();
    sort(nodes.begin(), nodes.end(), cmp);
    for (int i = 0; i + 1 < m; ++ i) {
        int u = nodes[i], v = nodes[i + 1];
        int w = getLca(u, v);
        nodes.push_back(w);
    }
    sort(nodes.begin(), nodes.end(), cmp);
    nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
    m = (int)nodes.size();
    for (int i = 0; i < m; ++i) {
        int u = nodes[i];
        virAdj[u].clear();
        dp[u] = -1;
    }
    for (int i = 0; i + 1 < m; ++ i) {
        int u = getLca(nodes[i], nodes[i + 1]);
        int v = nodes[i + 1];
        cout << u << " " << v << endl;
        virAdj[u].push_back(v);
    }
}

void calc(int u, int d) {
    dp[u] = 0;
    for (int v : virAdj[u]) {
        if (dp[v] == -1) {
            calc(v, d);
        }
        dp[u] += dp[v];
    }
    if (dp[u] < v[u] && x[u] % d == 0) {
        dp[u] = v[u];
    }
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    virAdj.assign(n + 1, vector<int>());

    for (int i = 2; i <= n; ++i) {
        int par;
        cin >> par;
        adj[par].push_back(i);
    }

    ++t;
    vector<int> candidates;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> v[i];
        for (int d : divs[x[i]]) {
            if (vis[d] != t) {
                vis[d] = t;
                nodes[d].clear();
                candidates.push_back(d);
            }
            nodes[d].push_back(i);
        }
    }

    sz = 0;
    h[1] = 1;
    dfs(1);
    buildLca();

    candidates = {19};

    long long res = 0, ru, rd;
    for (int d : candidates) {
        buildVirtualTree(nodes[d]);
        for (int i = 1; i <= n; ++i) {
            cout << i << ": ";
            for (int j : virAdj[i]) cout << j << " ";
            cout << endl;
        }
        for (int u : nodes[d]) {
            if (dp[u] == -1) {
                calc(u, d);
            }
            if (res < dp[u] * d) {
                res = dp[u] * d;
                ru = dp[u];
                rd = d;
            }
        }
    }
    cout << ru << " " << rd << endl;
    cout << res << '\n';
}

int main() {
    freopen(task".inp","r",stdin);
    freopen(task"_d.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
//    cin >> numTest;
    init();
    while(numTest--) {
        solve();
    }
    return 0;
}
