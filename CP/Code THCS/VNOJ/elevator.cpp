#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORA(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

template <class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template <class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; }

// end of template

struct Block {
	int h, a, c;
};

const int MAXN = 401, MAX = 4e4 + 11, INF = 1e9 + 11;

Block blocks[MAXN];
int k, dp[MAXN][MAX];

bool cmp(const Block &a, const Block &b) {
	return a.a < b.a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("nvt.inp", "r", stdin);
//	freopen("nvt.out", "w", stdout);

	cin >> k;
	FORE(i, 1, k) cin >> blocks[i].h >> blocks[i].a >> blocks[i].c;
	sort(blocks+1, blocks+1+k, cmp);

//	FORE(i, 1, k) cout << blocks[i].a << " " << blocks[i].h << " " << blocks[i].c << "\n";

	int ans = 0;
	blocks[0].a = INF;
	memset(dp, 0, sizeof dp);
	FORE(i, 1, k) {
		FORE(j, 1, blocks[i].a) {
			FORE(d, 0, blocks[i].c) {
				int heightInc = d * blocks[i].h;
				if (j >= heightInc && j - heightInc <= blocks[i-1].a) {
	//				cout << heightInc << " ";
					maximize(dp[i][j], dp[i-1][j - heightInc] + heightInc);
				}
			}
//			cout << dp[i][j] << " ";
			maximize(ans, dp[i][j]);
		}
//		cout << "\n";
	}

	cout << ans;

	return 0;
}

/// Goi dp[i][j] la do cao max khi xet i blocks dau va do cao hien tai la j
/// dp[i][j] = dp[i-1][j - t * blocks[i].h] + t * blocks[i].h
/// j >= t * blocks[i].h (t: 1-> blocks[i].c)
