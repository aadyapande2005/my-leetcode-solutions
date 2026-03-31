class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = friends.size();
        queue<pair<int,int>> q;
        vector<bool> vis(n);
        unordered_map<string,int> freq;

        q.push({id, 0});
        vis[id] = true;

        while(!q.empty())
        {
            auto [node, lvl] = q.front();
            q.pop();

            if(lvl > level) break;

            // cout<<"current --> "<<node<<endl;

            if(lvl == level)
            {
                // cout<<"movies by "<<node<<" --> ";
                for(string movie:watchedVideos[node]) 
                {
                    freq[movie]++;
                    // cout<<movie<<" ";
                }
                // cout<<endl;
            }
            
            for(int adj:friends[node])
            {
                if(!vis[adj])
                {
                    vis[adj] = true;
                    q.push({adj, lvl+1});                   
                }
            }
            // cout<<endl;
        }
        
        vector<string> ans;
        
        vector<pair<string,int>> arr(freq.begin(), freq.end());

        sort(arr.begin(), arr.end(), [](pair<string,int>&a, pair<string,int>&b)
            {
                if(a.second == b.second) return a.first < b.first;
                return a.second < b.second;
            }
        );

        for(auto it:arr) ans.push_back(it.first);

        return ans;
    }
};