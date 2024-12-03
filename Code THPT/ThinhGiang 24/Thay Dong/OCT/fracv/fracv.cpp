// Author: tinhnopro (tinhngo)
#include<bits/stdc++.h>

#define name "fracv"
#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define all(v) (v).begin(), (v).end()
#define szv(v) int((v).size())
#define sqr(x) 1ll * (x) * (x)
#define mask(x) (1LL << (x))
#define getbit(i, mask) ((mask >> i) & 1LL)
#define onbit(i, mask) (mask | MASK(i))
#define offbit(i, mask) mask & ~(MASK(i))
#define cntbit(x) __builtin_popcountll(x)

using namespace std;

using ll = long long;
using db = long double;
using vi = vector<int>;

template<class T> using pairD = pair<T, T>;  

template<class T> using vector2d = vector<vector<T>>;

template<class X, class Y> bool maximize(X &a, Y b) { 
	return a < b ? a = b, 1 : 0; 
}

template<class X, class Y> bool minimize(X &a, Y b) { 
	return a > b ? a = b, 1 : 0; 
}

template<class T> T Abs(const T &x) {
	return x < 0 ? -x : x;
}	
//_______________________________________________________________________

const int MAXN = 5e5 + 11; // const int MAX = 1e6 + 11;
// const int MOD = 1e9 + 7; 
// const int INF = 1e9 + 11; // const ll INFF = 1e18 + 11; 

struct Frac {
	ll x, y; 

	Frac() {
		x = y = 0;
	}

	Frac(int _x, int _y): x(_x), y(_y) {}

	Frac operator+(const Frac &other) {
		Frac ans; 
		ans.x = x + other.x;
		ans.y = y + other.y; 

		return ans;
	}

	bool operator<(const Frac &other) const {
		return x * other.y < y * other.x;
	}

	bool operator==(const Frac &other) const {
		return x * other.y == y * other.x;
	}
};

Frac d[MAXN];
int h, n;
ll num[MAXN]; 

void getPos(Frac cur, ll pos, Frac st0, Frac st1, int idx) {
	if (cur == d[idx]) {
		num[idx] = pos;
		return ;
	}

	Frac cur1 = cur + st0;
	Frac cur2 =	cur + st1;

	if (d[idx] < cur) {
		getPos(cur1, pos * 2, st0, cur, idx);
	} else {
		getPos(cur2, pos * 2 + 1, cur, st1, idx);
	}
}

vector<ll> List;

void process(void) {
	cin >> h >> n; 
	FOR(i, 1, n) {
		cin >> d[i].x >> d[i].y;
		getPos({1, 1}, 1, {0, 1}, {1, 0}, i);
		List.push_back(num[i]);
	}

	List.push_back(1);

	sort(all(List));
	deque<ll> dq; 

	ll res = 0;

	while (szv(List) + szv(dq) > 1) {
		while (szv(List) >= 2 && List.back() == List[szv(List) - 2]) List.pop_back();
		
		ll l = List.back();
		List.pop_back();
		res++;
		l /= 2; 

		dq.push_back(l);

		while (szv(dq) >= 2) {
			ll f = dq.front();
			dq.pop_front();
			if (f != dq.front()) {
				dq.push_front(f);
				break;
			}
		} 

		while (szv(dq) && (szv(List) == 0 || List.back() <= dq.front())) {
			List.push_back(dq.front());
			dq.pop_front();
		}

		while (szv(List) >= 2 && List.back() == List[szv(List) - 2]) List.pop_back();
	}

	cout << res;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);

	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//___________________________________
	// int t; cin >> t; while (t--)
	process();

	cerr << "\nRuntime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
	return 0;
}
