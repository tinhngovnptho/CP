/**
 * Author : tinhnopro
 * Created : 11-8-2024
 * Based on code by: tourist, tmwilliamlin168
 */
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const char &c) {
	return string(1, c);
}

string to_string(const string& s) {
	return s;
}

string to_string(const char* c) {
	return to_string((string) c);
}

string to_string(bool a) {
	return a ? "true" : "false";
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += char('0' + x);
	}
	res += "}";
	return res;
}

template<size_t S>
string to_string(bitset<S> b) {
	string res = "";
	for (size_t i = 0; i < S; ++i) {
		res += char('0' + b[i]);
	}
	return res;
}

template<typename T>
string to_string(T v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void DBG() {
	cerr << "]" << endl;
}

template<class H, class... T>
void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef tinhnop_local
#define debug(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...) 0
#endif // tinhnop_local
