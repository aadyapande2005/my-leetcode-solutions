class Solution {
public:
    int n, m;
    vector<vector<vector<vector<int>>>> dp;
    vector<vector<int>> grid;
    
    int sol(int i, int j, int direction, int k)
    {
        // cout<<i<<" "<<j<<endl;
        if(k < 0) return 1e9;
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j][k][direction] != -1) return dp[i][j][k][direction];


        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int dir[] = {0, 1, 2, 3};

        int res = 1e9;

        for(int a=0; a<4; a++)
        {
            int x = i + dx[a];
            int y = j + dy[a];         
            int d = dir[a];

            if(x>=0 && y>=0 && x<n && y<m)
            {
                if(direction == 4 || d == direction) 
                    res = min(res, sol(x, y, d, k));
                else 
                    res = min(res, sol(x, y, d, k-1));
            }
        }
        return dp[i][j][k][direction] = grid[i][j] + res;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(
            n, vector<vector<vector<int>>>(
                m, vector<vector<int>>(
                    k+1, vector<int>(
                        5, -1
                    )
                )
            )            
        );

        this->grid = grid;        

        int ans = sol(0, 0, 4, k); 

        return ans >= 1e9 ? -1 : ans;
    }
};