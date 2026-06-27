class Solution {
public:
    int n;

    // int sol(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &dp)
    // {
    //     if(x == n-1) return grid[x][y];
    //     if(dp[x][y] != -1) return dp[x][y];

    //     int ans = 1e9;
    //     for(int k=0; k<n; k++)
    //     {
    //         if(k != y)
    //         {
    //             // cout<<"-- "<<k<<" "<<y+1<<endl;
    //             ans = min(ans, grid[x][y] + sol(x+1, k, grid, dp));
    //         }
    //     }

    //     return dp[x][y] = ans;
    // }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = 1e9;

        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int i=0; i<n; i++) dp[0][i] = grid[0][i];

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int mini = 1e9;
                for(int k=0; k<n; k++)
                {
                    if(k != j)
                    {   
                        mini = min(mini, dp[i-1][k]);
                    }                         
                }
                dp[i][j] += mini + grid[i][j];
            }
        }

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
            
        // }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};