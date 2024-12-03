#define taskname "LEXORDER"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using lli = long long;
constexpr int MAX_N = 1e5 + 1;

int n;
lli k;
int p[MAX_N], f[MAX_N];
int tree[MAX_N];
int maxbit;

void ReadInput()
{
    cin >> n >> k;
    for (int i = n; i >= 1; --i) cin >> p[i];
}

void Increase(int x, int Delta)
{
    for (; x <= n; x += x & -x)
        tree[x] += Delta;
}

int Query(int x)
{
    int res = 0;
    for (; x > 0; x &= x - 1)
        res += tree[x];
    return res;
}

int Find(int v)
{
    int x = 0;
    for (int step = maxbit; step > 0; step /= 2)
        if (x + step <= n && tree[x + step] < v)
        {
            x += step;
            v -= tree[x];
        }
    return x + 1;
}

void Init()
{
    fill(tree + 1, tree + n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        f[i] = Query(p[i]);
        Increase(p[i], 1);
    }
    maxbit = 1;
    while (maxbit <= n / 2) maxbit *= 2;
}

bool Solve()
{
    for (int i = 1; i <= n; ++i)
    {
        k += f[i];
        f[i] = k % i;
        k = k / i;
        if (k == 0) break;
    }
    return k == 0;
}

void Print()
{
    for (int x = 1; x <= n; ++x)
        tree[x] = x & -x;
    for (int i = n; i >= 1; --i)
    {
        p[i] = Find(f[i] + 1);
        Increase(p[i], -1);
    }
    for (int i = n; i >= 1; --i)
        cout << p[i] << ' ';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Init();
    if (!Solve()) cout << -1;
    else Print();
}