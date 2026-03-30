class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<int> indeg(n);

        for(auto edge:edges)
        {
            indeg[edge[1]]++;
        }

        bool flag = false;
        int ans = -1;

        for(int i=0; i<n; i++)
        {
            if(indeg[i] == 0)
            {
                if(flag) return -1;
                flag = true;
                ans = i;
            }
        }

        return ans;
    }
};