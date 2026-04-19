class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for(int i=0,j=0; i<n;)
        {
            if(i > j) j++;
            else if(i <= j)
            {
                if(j<m && nums1[i] <= nums2[j])
                {
                    ans = max(ans, j-i);
                    j++;
                } 
                else
                {
                    i++;
                }
            }
        }

        return ans;
    }
};