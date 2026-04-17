class Solution {
public:
    int rev(int num)
    {
        string temp = to_string(num);
        reverse(temp.begin(), temp.end());

        return stoi(temp);
    }
    int minMirrorPairDistance(vector<int>& nums) {

        /*
            12  21  45  33  54           
                            ^   
            ans = 1
            
            21, 0
            54, 2
            33, 3
        */

        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int num = nums[i];

            int rev_num = rev(num);

            // cout<<num<<" "<<rev_num<<endl;

            if(mp.count(num)) ans = min(ans, abs(mp[num] - i));
            mp[rev_num] = i;
        }

        // for(auto it:mp)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        return ans == INT_MAX ? -1 : ans;
    }
};