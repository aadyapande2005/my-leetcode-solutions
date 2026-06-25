class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            int cnt = 0;
            for(int j=i; j<n; j++)
            {
                float size = j - i + 1;
                if(nums[j] == target) cnt++;
                if(cnt > size/2) ans++;
            }
        }
        return ans;
    }
};