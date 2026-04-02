class Solution {
public:
    const int NEG_INF = -1e9;

    int sol(int i, int j, int k, int n, int m,
            vector<vector<int>>& coins,
            vector<vector<vector<int>>> &dp)
    {
        if(i == n-1 && j == m-1)
        {
            if(coins[i][j] < 0 && k >= 1) return 0;
            return coins[i][j];
        }

        if(i == n || j == m) return NEG_INF;

        if(dp[i][j][k] != NEG_INF) return dp[i][j][k];

        int take = max(
            sol(i+1, j, k, n, m, coins, dp),
            sol(i, j+1, k, n, m, coins, dp)
        );

        int ans = NEG_INF;

        // take coin
        if(take != NEG_INF)
            ans = take + coins[i][j];

        // neutralize
        if(coins[i][j] < 0 && k >= 1)
        {
            int neut = max(
                sol(i+1, j, k-1, n, m, coins, dp),
                sol(i, j+1, k-1, n, m, coins, dp)
            );
            ans = max(ans, neut);
        }

        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, NEG_INF))
        );

        return sol(0, 0, 2, n, m, coins, dp);
    }
};