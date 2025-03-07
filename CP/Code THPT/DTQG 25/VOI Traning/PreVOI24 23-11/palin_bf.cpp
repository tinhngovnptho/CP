/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-24
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "D:\Tinhnopro\header\debug.h"
#else
#define debug(...)
#endif // LOCAL

#if __cplusplus < 202002L
template <class T> int ssize(const T &a) { return a.size(); }
#endif // __cplusplus

template <class A, class B>
bool maximize(A& a, B b) {
	return a < b ? a = b, true : false;
}

template <class A, class B>
bool minimize(A& a, B b) {
	return a > b ? a = b, true : false;
}

using int64 = long long;

const int maxN = 3e6 + 11;
const int64 BASE = 311;
const int64 MOD = 1e9 + 7;

int n, k;
char s[maxN];

struct Poly_hash {
    vector<int64> hashS, hashRS, Pow;
    int length;

    void init(const char *s, int _sz) {
        length = _sz;

				string rev;
        for(int i = length; i >= 1; --i) rev.push_back(s[i]);
				rev = " " + rev;

        hashS.assign(length + 1, 0);
        hashRS.assign(length + 1, 0);
        Pow.assign(length + 1, 0);

        Pow[0] = 1;

        for(int i = 1; i <= length; ++i) {
            Pow[i] = Pow[i - 1] * BASE % MOD;
            hashS[i] = (hashS[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
            hashRS[i] = (hashRS[i - 1] * BASE + rev[i] - 'a' + 1) % MOD;
        }
    }

    int64 getHash(int i, int j) {
        return (hashS[j] - hashS[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
    }

    int64 getHashR(int i, int j) {
        return (hashRS[length - i + 1] - hashRS[length - j] * Pow[j - i + 1] + MOD * MOD) % MOD;
    }

    bool isPalin(int i, int j) {
        return (getHash(i, j) == getHashR(i, j));
    }
} Hash;

namespace Sub12 {

	bool checkLen(int len, int sz) {
		for (int i = 1; i <= sz - len + 1; ++i) {
			if (Hash.isPalin(i, i + len - 1)) {
					return true;
			}
		}
		return false;
	}

	void solve() {
		for (int i = n + 1, id; i <= k * n; ++i) {
			id = i % n + (i % n == 0 ? n : 0);
			s[i] = s[id];
		}

		int sz = k * n;
		Hash.init(s, sz);
		int ans = 0;

		int l = 2, r = sz - (sz % 2);
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (mid & 1) mid++;
			cout << mid << ' ' << checkLen(mid, sz) << '\n';
			if (checkLen(mid, sz)) l = mid;
			else r = mid - 2;
		}

		maximize(ans, l);

		l = 1, r = sz - (sz % 2 == 0);
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (mid % 2 == 0) mid++;
			if (checkLen(mid, sz)) l = mid;
			else r = mid - 2;
		}

		maximize(ans, l);

		cout << ans;
	}
}

namespace SubLao {

	bool checkLen(int len, int sz) {
		for (int i = 1; i <= sz - len + 1; ++i) {
			if (Hash.isPalin(i, i + len - 1)) {
					return true;
			}
		}
		return false;
	}

	void solve() {
		Hash.init(s, n);
		int ans = 0;

		int l = 2, r = n - (n % 2);
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (mid & 1) mid++;
			if (checkLen(mid, n)) l = mid;
			else r = mid - 2;
		}

		maximize(ans, l);

		l = 1, r = n - (n % 2 == 0);
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (mid % 2 == 0) mid++;
			if (checkLen(mid, n)) l = mid;
			else r = mid - 2;
		}

		maximize(ans, l);

		cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("palin.inp", "r", stdin);
	freopen("palin.ans", "w", stdout);


	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	return SubLao::solve(), 0;
}
