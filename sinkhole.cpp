#include <iostream>
#include <vector>
#include <algorithm> // for min function
using namespace std;
#define INT_MAX 100000;

int xb, yb, xt, yt;
bool used;

int fun(vector<vector<int>>& dp, int N, int M, int k) {
    int msum = INT_MAX;
    for (int i = 0; i <= N - k; i++) {
        for (int j = 0; j <= M - k; j++) {
            int sum = dp[i + k][j + k] - dp[i + k][j] - dp[i][j + k] + dp[i][j];
            if (sum < msum) {
                msum = sum;
                if ((msum == 1 && !used) || msum == 0) {
                    if (msum == 0) used = true;
                    xb = i + k;
                    yb = j + 1;
                    xt = i + 1;
                    yt = j + k;
                }
            }
        }
    }
    return msum;
}

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
        
        // Read input into mat and compute prefix sums
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int value;
                cin >> value;
                mat[i][j] = value + mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
            }
        }

        // Binary search to find the maximum valid square size
        int l = 1, r = min(n, m);
        int ones;
        
        while (l < r) {
            int mid = (l + r) / 2;
            used = false;
            ones = fun(mat, n, m, mid);
            if (ones > 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << "Test case #" << test << ": ";
        cout << xb << " " << yb << " " << xt << " " << yt << endl;
    }

    return 0;
}
