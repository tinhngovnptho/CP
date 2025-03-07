#include <bits/stdc++.h>

using namespace std;

int a[4], cnt[4];

void check(int idx1, int idx2) {
    if (a[idx1] == a[idx2]) {
        cnt[idx1] += 1;
        cnt[idx2] += 1;
        return;
    }
    cnt[idx1] += a[idx1] > a[idx2] ? 3 : 0;
    cnt[idx2] += a[idx2] > a[idx1] ? 3 : 0;
}

void process(int idx1, int idx2) {
    cin >> a[idx1] >> a[idx2];
    check(idx1, idx2);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    process(1, 2); process(1, 3); process(2, 3);
    for (int i = 1; i <= 3; ++i) cout << cnt[i] << " ";
}
