#include <iostream>
#include <string>
#include <vector>

int longestSymmetricSubstringInFibonacci(const std::string& a, const std::string& b, int k) {
    std::string fib[2] = {a, b};
    int result = 0;

    if (k == 0) {
        return fib[0].length();
    } else if (k == 1) {
        return fib[1].length();
    }

    for (int i = 2; i <= k; ++i) {
        std::string current = fib[0] + fib[1];
        int len = current.length();

        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));

        for (int l = 1; l <= len; ++l) {
            for (int start = 0; start <= len - l; ++start) {
                int end = start + l - 1;

                if (l == 1) {
                    dp[start][end] = true;
                } else if (l == 2) {
                    dp[start][end] = (current[start] == current[end]);
                } else {
                    dp[start][end] = (current[start] == current[end]) && dp[start + 1][end - 1];
                }

                if (dp[start][end] && l > result) {
                    result = l;
                }
            }
        }

        fib[0] = fib[1];
        fib[1] = current;
    }

    return result;
}

int main() {
    std::string a = "a";
    std::string b = "b";
    int k = 20;

    int result = longestSymmetricSubstringInFibonacci(a, b, k);
    std::cout << "Do dai xau con doi xung dai nhat trong f_" << k << " la: " << result << std::endl;

    return 0;
}
