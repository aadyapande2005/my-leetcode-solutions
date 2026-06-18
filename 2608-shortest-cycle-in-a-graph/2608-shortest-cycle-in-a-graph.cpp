class Solution {
public:
    int shortest_cycle(int node, int n, vector<vector<int>>& adj)
    {
        if(adj[node].size() == 0) return INT_MAX;
        vector<int> dist(n, -1);
        vector<int> parent(n);
        
        // for(int i=0; i<n; i++) parent[i] = i;

        queue<pair<int,int>> q;
        q.push({node, 0});
        dist[node] = 0;

        int ans = INT_MAX;

        while(!q.empty())
        {
            auto [curr, d] = q.front();
            q.pop();  

            // cout<<curr<<endl;     
            // for(int x:parent) cout<<x<<" ";

            for(int adjnode : adj[curr])
            {
                if(dist[adjnode] == -1)
                {
                    q.push({adjnode, d+1});
                    parent[adjnode] = curr;
                    dist[adjnode] = d+1;
                }
                else if(parent[curr] != adjnode)
                {
                    // cout<<dist[adjnode]<<" "<<dist[curr];
                    ans = min(ans, dist[adjnode] + dist[curr] + 1);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);          
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int temp = shortest_cycle(i, n, adj);
            // cout<<i<<" "<<temp<<endl;
            if(temp != -1) ans = min(ans, temp);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};