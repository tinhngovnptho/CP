#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> frac;

deque<pair<ll, ll>> H; // Holds lines in form of (slope, intercept)

// Compare two fractions frac1 = a/b, frac2 = c/d
bool cmp(const frac &frac1, const frac &frac2) {
    return frac1.first * frac2.second < frac2.first * frac1.second;
}

// Calculate the intersection point of two lines
frac intersection(const pair<ll, ll> &line1, const pair<ll, ll> &line2) {
    ll num = line2.second - line1.second;
    ll den = line1.first - line2.first;
    if (den < 0) {
        num = -num;
        den = -den;
    }
    return {num, den};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll c;
    cin >> n >> c;

    set<ll> x_set;
    for (int i = 0; i < n; ++i) {
        ll xi;
        cin >> xi;
        x_set.insert(xi);
    }

    vector<ll> x(x_set.begin(), x_set.end());
    n = x.size();

    H.clear();
    H.emplace_back(-2 * x[0], x[0] * x[0]);

    ll dp = 0;

    for (int i = 0; i < n; ++i) {
        // Remove unnecessary lines from deque
        while (H.size() >= 2 && cmp(intersection(H[0], H[1]), {x[i], 1})) {
            H.pop_front();
        }

        // Compute dp[i]
        dp = x[i] * x[i] + c + H[0].first * x[i] + H[0].second;

        if (i == n - 1) break;

        // Insert new line into deque
        pair<ll, ll> new_line = {-2 * x[i + 1], x[i + 1] * x[i + 1] + dp};
        while (H.size() >= 2) {
            pair<ll, ll> last_line = H.back(); H.pop_back();
            pair<ll, ll> pen_line = H.back(); H.pop_back();

            frac l_current = intersection(last_line, pen_line);
            frac point = intersection(new_line, last_line);

            H.push_back(pen_line);

            if (cmp(l_current, point)) {
                H.push_back(last_line);
                H.push_back(new_line);
                break;
            }
        }
        if (H.size() < 2) {
            H.push_back(new_line);
        }
    }

    cout << dp << '\n';

    return 0;
}
