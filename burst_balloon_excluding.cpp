#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxCoins(const vector<int>& A) {
    int siz = A.size();
    vector<int> nums(siz + 2, 1);
    int n = 1;
    for (int i = 0; i < siz; i++) {
        if (A[i] > 0) {
            nums[n++] = A[i];
        }
    }
    nums.resize(n + 1, 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len < n + 1; ++len) {
        for (int left = 0; left < n + 1 - len; ++left) {
            int right = left + len;
            for (int i = left + 1; i < right; ++i) {
                dp[left][right] = max(
                    dp[left][right],
                    nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]
                );
            }
        }
    }

    return dp[0][n];
}
