class Solution {
public:
    vector<int> digitize(int n)
    {
        vector<int> digits;
        while(n > 0)
        {
            digits.push_back(n%10);
            n /= 10;
        }
        return digits;        
    }
    int concat(vector<int>&arr)
    {
        int n = 0;
        for(int i=0; i<arr.size(); i++)
            n += arr[i]*pow(10, i);

        return n;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> temp;
        for(int i=0; i<n; i++)
        {
            int n = nums[i];
            vector<int> digits = digitize(n);
            if(digits.size() == 0) digits.push_back(0);
            for(int j=0; j<digits.size(); j++) digits[j] = mapping[digits[j]];
            int mapped = concat(digits);
            temp.push_back({mapped, i});
        }

        sort(temp.begin(),temp.end());

        vector<int> ans;
        for(auto x:temp) ans.push_back(nums[x.second]);
        // for(auto x:temp) ans.push_back(x.first);

        return ans;        
    }
};