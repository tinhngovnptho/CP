#include <bits/stdc++.h>

#define For(i,a,b) for(int i = a; i <= b; i++)
#define Ford(i,a,b) for(int i = a; i >= b; i--)
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define RRH(v) v.resize(unique(all(v)) - v.begin())

using namespace std;
const int  N = 1e6+7;
const int M = 1e9+7;
const ll oo = 3e18;

int n, m, a[N];
int dp[N];
ll pre[N];

struct BIT {
	int bit[N];
	void memset() {
		For(i, 0, N / 10) bit[i] = N;
	}

	void up(int x, int val) {
		for(; x > 0; x -= x& - x) bit[x] = min(bit[x], val);
	}

	int get(int x) {
		int ans = M;
		for(; x <= N / 10; x += x& - x) ans = min(ans, bit[x]);
		return ans;
	}
} T;

vector<ll> v;

int tknp(ll val) {
	int l = 0;
	int r = v.size() - 1;
	int ans = -2;
	while(l <= r) {
		int mid = l + r >> 1;
		if(v[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans + 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    #define TASK ""
    if (fopen (".inp", "r")) {
        freopen (".inp", "r", stdin);
        freopen (".out", "w", stdout);
    }
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

	cin >> n >> m;
	pre[0] = 0;
	dp[0] = 0;
	v.push_back(0);
	For(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i], dp[i] = N, v.push_back(pre[i]);
	T.memset();
	sort(all(v));
	RRH(v);
	int j = lower_bound(all(v), 0) - v.begin() + 1;
	T.up(j, 0);

	For(i, 1, n) {
		j = tknp(pre[i] - m);
		if(j != -1) dp[i] = T.get(j) + 1;
		j = lower_bound(all(v), pre[i]) - v.begin() + 1;
		T.up(j, dp[i]);
	}

	cout << dp[n];
    return 0;
}
