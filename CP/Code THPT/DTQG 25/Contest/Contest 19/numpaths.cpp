/*
	Author: Tinhnopro (Tinh nop)
	From: CHV Phu Tho
 */
#include <bits/stdc++.h>

using namespace std;

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
	static_assert(D >= 1);
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

const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 11; 

int ifact[MAXN], fact[MAXN], PowA[MAXN], PowB[MAXN], PowC[MAXN];
int n, m, a, b, c; 

int Pow(int a, int b) {
	int res = 1; 
	for (; b; b >>= 1, a = 1ll * a * a % MOD) if (b & 1) {
		res = 1ll * res * a % MOD;
	}
	return res;
}

void preprocess(void) {
	PowA[0] = PowB[0] = PowC[0] = 1;
	fact[0] = 1; 
	PowA[1] = a; 
	PowB[1] = b; 
	PowC[1] = c;
	for (int i = 2; i <= n + m; ++i) {
		PowA[i] = 1ll * PowA[i - 1] * a % MOD;
		PowB[i] = 1ll * PowB[i - 1] * b % MOD;
		PowC[i] = 1ll * PowC[i - 1] * c % MOD;
	}
	for (int i = 1; i <= n + m; ++i) fact[i] = 1ll * fact[i - 1] * i % MOD;
	ifact[n + m] = Pow(fact[n + m], MOD - 2);
	for (int i = n + m - 1; i >= 0; --i) ifact[i] = 1ll * ifact[i + 1] * (i + 1) % MOD;
}

int Ckn(int n, int k) {
	if (k > n) return 0;
	return (1ll * fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
}

void add(int &a, int b) {
	a += b; 
	if (a >= MOD) a -= MOD;
}

void Tinhnopro(void) {
	cin >> n >> m >> a >> b >> c; 
	
	preprocess();

	int ans = 0; 

	for (int k = 0; k <= min(m, n); ++k) {
		int res = 1ll * PowA[n - k] * PowB[m - k] % MOD;
		res = 1ll * res * PowC[k] % MOD;
		res = 1ll * res * Ckn(n + m - k, k) % MOD;
		res = 1ll * res * Ckn(n + m - 2 * k, n - k) % MOD;
		add(ans, res);
	}
	cout << ans; 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#define name "numpaths"
	if (fopen(name".inp", "r")) 
		freopen(name".inp", "r", stdin),
		freopen(name".out", "w", stdout); 

	// int t; cin >> t; while (t--)
	Tinhnopro();

	cerr << "\nRuntime: " << 1.0 * clock() / CLOCKS_PER_SEC << ".s \n";
	return 0;
}
