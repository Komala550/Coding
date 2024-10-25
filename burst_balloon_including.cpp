int maxCoins(int N, vector<int> &arr) 
    {
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        N = arr.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int length = 2; length < N; length++) 
        {
            for (int left = 0; left < N - length; left++) 
            {
                int right = left + length;
                for (int i = left + 1; i < right; i++) 
                {
                    int before = dp[left][i];
                    int after = dp[i][right];
                    int prod = arr[left] * arr[i] * arr[right];
                    dp[left][right] = max(dp[left][right], prod + before + after);
                }
            }
        }

    // Return the maximum coins collected between the first and the last added balloons
    return dp[0][N - 1];
    }
