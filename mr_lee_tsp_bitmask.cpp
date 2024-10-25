class Solution {
public:
int tspUtil(int pos, int visited, vector<vector<int>>& cost, vector<vector<int>>& dp, int VISITED_ALL) {
        int n = cost.size();
        if (visited == VISITED_ALL) {
            return cost[pos][0];
        }
        if (dp[pos][visited] != -1) {
            return dp[pos][visited];
        }

        int ans = INT_MAX;
        for (int city = 0; city < n; city++) {
            if ((visited & (1 << city)) == 0) {  // If city is not visited
                int newAns = cost[pos][city] + tspUtil(city, visited | (1 << city), cost, dp, VISITED_ALL);
                ans = min(ans, newAns);
            }
        }
        dp[pos][visited] = ans;
        return ans;
    }
int total_cost(vector<vector<int>>cost)
{
    int n = cost.size();
    int VISITED_ALL = (1 << n) - 1;  // All cities visited
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    return tspUtil(0, 1, cost, dp, VISITED_ALL);
    
}
};
