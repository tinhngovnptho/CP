/*
    Author: Tinhnopro (Tinh nop)
    From: CHV Phu Tho
 */
#include <bits/stdc++.h>

using namespace std;

template <typename T, int D>
struct vec : public vector<vec<T, D - 1>> {
    static_assert(D >= 1, "Init error");
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
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define name ""

int main(void) {
    for (int test = 1; test <= 100; ++test) {
        ofstream cout(name".inp");

        cout.close();

        system(name".exe");
        system(name"_bf.exe");
        if (system("fc " name ".out " name ".ans") != 0) {
            cerr << "WA";
            return 0;
        }
    }
    return 0;
}
