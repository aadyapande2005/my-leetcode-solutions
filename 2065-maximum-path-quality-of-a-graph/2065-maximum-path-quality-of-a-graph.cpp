class Solution {
public:
    int ans = 0;

    void dfs(int node, int time, int score, vector<int> &freq, vector<vector<pair<int,int>>> &adj, vector<int> &values)
    {
        if(freq[node] == 0) score += values[node];

        if(node == 0) ans = max(ans, score);

        freq[node]++;

        for(auto [v, t] : adj[node])
        {
            if(time-t >= 0) dfs(v, time-t, score, freq, adj, values); 
        }

        freq[node]--;
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<int> freq(n);

        dfs(0, maxTime, 0, freq, adj, values);

        return ans;
    }
};