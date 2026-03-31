class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<bool>> vis(n, vector<bool>(1<<n, false));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++)
        {
            q.push({{i, 1<<i},0});
            vis[i][1<<i] = true;
        }

        while(!q.empty())
        {
            auto [t, d] = q.front();
            auto [node, mask] = t;
            q.pop();

            if(mask == (1<<n) - 1) return d;

            for(int adj : graph[node])
            {
                if(!vis[adj][mask | 1<<adj])
                {
                    int new_mask = mask | 1<<adj;
                    vis[adj][new_mask] = true;
                    q.push({{adj, new_mask},d+1});
                }
            }
        }

        return -1;
    }
};