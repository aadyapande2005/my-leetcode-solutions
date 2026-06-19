class Solution {
public:
    vector<long long> dijstra(int node, int n, vector<vector<pair<int,int>>>& adj)
    {
        vector<long long> dist(n, 1e18);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, node});
        dist[node] = 0;

        while(!pq.empty())
        {
            auto [d, curr] = pq.top();
            pq.pop();

            if(dist[curr] < d) continue;

            for(auto adjnode : adj[curr])
            {
                int nd = adjnode.first;
                int wt = adjnode.second;
                
                if(dist[nd] > wt + dist[curr])
                {
                    dist[nd] = wt + dist[curr];
                    pq.push({dist[nd], nd});
                }
            }
        }

        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<pair<int,int>>> rev(n);

        for(auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> s1 = dijstra(src1, n, adj);
        vector<long long> s2 = dijstra(src2, n, adj);
        vector<long long> d = dijstra(dest, n, rev);

        long long ans = 1e18;

        for(int i=0; i<n; i++)
        {
            long long temp = s1[i] + s2[i] + d[i];
            ans = min(ans, temp);
        }

        return ans >= 1e18 ? -1 : ans;
    }
};