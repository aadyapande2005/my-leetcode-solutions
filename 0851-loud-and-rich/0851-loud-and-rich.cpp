class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> ans(n);
        vector<int> deg(n);

        for(int i=0; i<n; i++) ans[i] = i;

        for(auto x : richer)
        {
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        } 
        
        queue<int> q;
        
        for(int i=0; i<n; i++)
            if(deg[i] == 0) q.push(i);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(int adjnode : adj[curr])
            {
                if(quiet[ans[curr]] < quiet[ans[adjnode]]) ans[adjnode] = ans[curr];
                deg[adjnode]--;
                if(deg[adjnode] == 0) q.push(adjnode);
            }
        }        

        return ans;        
    }
};