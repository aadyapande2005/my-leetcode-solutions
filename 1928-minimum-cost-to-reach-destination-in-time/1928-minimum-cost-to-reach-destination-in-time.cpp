class Solution {
public:
    int dfs(int u, int dest, int time, int toll, vector<vector<pair<int,int>>> &adj, vector<int> &fee, vector<vector<int>> &dp)
    {
        if(time < 0) return 1e7;
        if(u == dest) return fee[u];
        if(dp[u][time] != -1) return dp[u][time];

        int ans = 1e7;
        for(auto [v, t] : adj[u])
        {
            ans = min(ans, fee[u] + dfs(v, dest, time-t, toll, adj, fee, dp));
        }

        return dp[u][time] = ans;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);

        vector<vector<int>> dp(n, vector<int> (maxTime+1, -1));

        for(auto e:edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int ans = dfs(0, n-1, maxTime, 0, adj, passingFees, dp);

        return ans >= 1e7 ? -1 : ans;
    }
};