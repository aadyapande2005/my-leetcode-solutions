class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length();
        long long count = 1;
        long long ans = 1;
        long long mod = 1e9 + 7;

        for(int i=1; i<n; i++)
        {
            if(s[i] == s[i-1]) count++;
            else count = 1;
            ans += count;
            ans %= mod;
        }

        return ans;
    }
};