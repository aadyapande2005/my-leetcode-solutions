class Solution {
public:
    vector<int> dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[node] = true;
        vector<int> nodes;
        nodes.push_back(node);

        for(int adjnode : adj[node])
        {
            if(!vis[adjnode])
            {
                vector<int> temp = dfs(adjnode, adj, vis);
                nodes.insert(nodes.end(),temp.begin(),temp.end());
            }
        }
        return nodes;
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
                vector<int> temp = dfs(i, adj, vis);
                int nodes = temp.size();

                int edges = 0;

                for(int node:temp)
                {
                    edges += adj[node].size();
                }         

                if(nodes*(nodes-1) == edges) ans++;
            }
        }

        return ans;
    }
};