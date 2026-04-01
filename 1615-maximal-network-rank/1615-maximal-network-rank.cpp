class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<int> freq(n);

        for(auto r:roads)
        {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
            freq[r[0]]++;
            freq[r[1]]++;
        }

        int ans = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int temp = freq[i]+freq[j];

                for(int node:adj[i])
                {
                    if(node == j)
                    {
                        temp -= 1;
                        break;
                    }
                }

                ans = max(ans, temp);
            }
        }

        return ans;
    }
};