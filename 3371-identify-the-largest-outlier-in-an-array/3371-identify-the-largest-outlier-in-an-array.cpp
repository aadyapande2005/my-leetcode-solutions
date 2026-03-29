class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;
        int ans = -1e5;

        unordered_map<int,int> mp;

        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        } 

        for(int i=0; i<n; i++)
        {
            int curr = nums[i];
            int curr_sum = sum - curr;
            
            if(curr_sum%2 == 0 && mp[curr_sum/2] != 0)
            {
                if(curr_sum/2 == curr && mp[curr_sum/2] == 1)
                    continue;
                else ans = max(ans, curr); 
            } 
        }


        return ans;
    }
};