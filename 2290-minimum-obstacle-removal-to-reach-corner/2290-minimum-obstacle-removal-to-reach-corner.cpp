class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e7));

        queue<pair<pair<int,int>, int>> q;

        int dx[] = {0,1,0,-1}; 
        int dy[] = {-1,0,1,0};

        int ans = 1e7;

        q.push({{0,0},0});
        dist[0][0] = 0;

        while(!q.empty())
        {
            auto [cor, d] = q.front();
            auto [x, y] = cor;
            q.pop();

            // cout<<x<<" "<<y<<endl;

            if(x == n-1 && y == m-1) ans = min(ans, dist[x][y]);

            for(int k=0; k<4; k++)
            {
                int i = x + dx[k];
                int j = y + dy[k];


                if(i>=0 and j>=0 and i<n and j<m)
                {
                    // cout<<"--"<<i<<" "<<j<<endl;
                    if(dist[i][j] > grid[i][j] + dist[x][y])
                    {
                        q.push({{i,j}, grid[i][j] + dist[x][y]});
                        dist[i][j] = grid[i][j] + dist[x][y];
                    }
                }
            }
        }

        return ans;
    }
};