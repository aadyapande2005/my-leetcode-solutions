class Solution {
public:
    pair<int,int> dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[node] = true;
        // cout<<node<<" --> ";

        int nodes = 1;
        int edges = adj[node].size();

        for(int adjnode : adj[node])
        {
            if(!vis[adjnode])
            {
                auto ans = dfs(adjnode, adj, vis);
                nodes += ans.first;
                edges += ans.second;
            }
        }

        return {nodes, edges};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n);

        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // for(auto nodes:adj)
        // {
        //     for(int node:nodes) cout<<node<<" ";
        //     cout<<endl;
        // }

        // cout<<endl;
        
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                auto [n, e] = dfs(i, adj, vis);
                // cout<<n<<" "<<e<<endl;
                if(n*(n-1) == e) ans++;
            }
        }

        return ans;
    }
};