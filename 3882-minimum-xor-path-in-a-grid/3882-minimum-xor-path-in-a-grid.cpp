class Solution {
public:
    int n, m;

    int dfs(int x, int y, int val, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid)
    {
        if(x == n-1 && y == m-1) return val ^ grid[x][y];
        if(dp[x][y][val] != -1) return dp[x][y][val];

        int ans = 1e9;
        if(x+1 < n) ans = min(ans, dfs(x+1, y, val ^ grid[x][y], dp, grid));
        if(y+1 < m) ans = min(ans, dfs(x, y+1, val ^ grid[x][y], dp, grid));

        return dp[x][y][val] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (1024, -1)));

        int ans = dfs(0, 0, 0, dp, grid);

        return ans;
    }
};