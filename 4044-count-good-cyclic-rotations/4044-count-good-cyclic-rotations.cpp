#define ll long long
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        ll tot = 0;
        ll n = nums.size();
        for(ll i=0; i<n; i++) tot += nums[i];

        ll size = 0;
        ll acc = 0;
        ll ans = 0;
        
        for(ll i=0; i<n+n/2; i++)
        {
            if(size < n/2)
            {
                acc += nums[i%n];
                size++;
            }
            else
            {
                if(acc > tot-acc) ans++;
                acc -= nums[(i-size)%n];
                acc += nums[i%n];
            }
        }
        return (int)ans;
    }
};