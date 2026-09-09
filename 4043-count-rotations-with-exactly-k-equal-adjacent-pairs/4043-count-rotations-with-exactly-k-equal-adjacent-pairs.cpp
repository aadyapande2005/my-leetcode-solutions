class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            int score = 0;
            for(int j=0; j<n-1; j++)
            {
                int curr = i+j;
                // cout<<s[curr%n]<<s[(curr+1)%n]<<" ";

                if(s[curr%n] == s[(curr+1)%n]) score++;
            }
            // cout<<endl;
            if(score == k) ans++;
        }
        return ans;
    }
};