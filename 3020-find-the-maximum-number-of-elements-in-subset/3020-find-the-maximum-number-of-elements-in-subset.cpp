class Solution {
public:
    int count(vector<int>::iterator it, int n, vector<int>& nums)
    {
        if(it == nums.end())
            return 0;

        int num = *it;
        //cout<<num<<endl;

        if(num > 31622) return 1;

        int sq_num = num*num;
        //cout<<num<<" "<<sq_num<<endl;

        auto x = lower_bound(it+1, nums.end(), num);
        auto xsq = lower_bound(it+1, nums.end(), sq_num);


        if(x != nums.end() && *x == num && xsq != nums.end() && *xsq == sq_num && x != xsq)
        {
            // cout<<"call to : "<<sq_num<<endl;
            return 2 + count(xsq, n, nums);
        }

        return 1;
    }
    int maximumLength(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int>::iterator it = nums.begin();

        int ans = 1;

        // for(int x:nums) cout<<x<<" ";
        // cout<<endl;

        int onecnt = 0;
        for(it; it != nums.end(); it++)
        {
            if(*it == 1) onecnt++;
            ans = max(ans, count(it, n, nums));
        }

        if(onecnt%2 == 0) onecnt--;

        return max(ans, onecnt);
    }
};