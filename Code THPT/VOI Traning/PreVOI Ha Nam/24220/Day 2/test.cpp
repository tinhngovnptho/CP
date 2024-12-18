#include <bits/stdc++.h>
#define TASK ""

using namespace std;

template <typename T>
int isize(const T& a) { return a.size(); }

template <typename T1, typename T2>
bool maximize(T1& a, T2 b) {
  return a < b ? a = b, true : false;
}

template <typename T1, typename T2>
bool minimize(T1& a, T2 b) {
  return a > b ? a = b, true : false;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (ifstream(TASK ".inp")) {
		freopen(TASK ".inp", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}


}
