class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int ans = INT_MIN;

        for(int x: gain)
        {
            ans = max(ans, curr);
            curr = x + curr;
        }
        return max(ans, curr);
    }
};