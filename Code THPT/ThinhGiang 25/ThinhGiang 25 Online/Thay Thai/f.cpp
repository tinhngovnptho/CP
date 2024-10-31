/*
	Author: Tinhnopro (Tinh nop)
	From: CHV Phu Tho
 */
#include <bits/stdc++.h>

using namespace std;

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
	static_assert(D >= 1, "Init Error");
	template <typename... Args>
	vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};

template <typename T>
struct vec<T, 1> : public vector<T> {
	vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};

template <typename T>
using tpair = pair<T, T>;

template <typename T>
int Size(const T &a) { return a.size(); }

template <typename T1, typename T2>
bool maximize(T1 &a, T2 b) {
	return a < b ? a = b, true : false;
}

template <typename T1, typename T2>
bool minimize(T1 &a, T2 b) {
	return a > b ? a = b, true : false;
}
// End of tempalte
const int MAXN = 1e5 + 11; 
const int LOG = 20;

int n, a[MAXN], s[MAXN];
unordered_map<int, vector<int>> pos;

struct RMQ {
	int st[LOG + 1][MAXN];
	
	void init(void) {
		for (int i = 1; i <= n; ++i) st[0][i] = a[i];
		for (int j = 1; j <= LOG; ++j) {
			for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
				st[j][i] = st[j - 1][i] & st[j - 1][i + (1 << (j - 1))];
			}
		}
	}

	int Get(int l, int r) {
		int k = log2(r - l + 1);
		return st[k][l] & st[k][r - (1 << k) + 1];
	}
} rmq;

void Tinhnopro(void) {
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	} 
	rmq.init();
	for (int i = 1; i <= n; ++i) {
		pos[s[i]].push_back(i);
	}

	int64_t ans = 0;

	for (int i = 1; i <= n; ++i) {
		int j = i; 
		while (j <= n) {
			int L = j, R = n, far = -1; 
			int val = rmq.Get(i, j);
			while (L <= R) {
				int mid = (L + R) >> 1; 
				if (rmq.Get(i, mid) == val) {
					far = mid; 
					L = mid + 1; 
				} else R = mid - 1; 
			}
			// cout << i << ' ' << j << ' ' << far << '\n';
			val ^= s[i - 1];
			if (pos.find(val) != pos.end()) {
				int left_pos = lower_bound(pos[val].begin(), pos[val].end(), j) - pos[val].begin();
				int right_pos = upper_bound(pos[val].begin(), pos[val].end(), far) - pos[val].begin() - 1; 
				ans += right_pos - left_pos + 1; 
			}
			j = far + 1; 
		}
	}

	cout << ans; 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#define name "f"
	if (fopen(name".inp", "r"))
		freopen(name".inp", "r", stdin),
		freopen(name".out", "w", stdout);

	// int t; cin >> t; while (t--)
	Tinhnopro();

	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s \n";
	return 0;
}
