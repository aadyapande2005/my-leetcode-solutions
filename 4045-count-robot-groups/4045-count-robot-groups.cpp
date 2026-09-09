#define ll long long
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        vector<int> narr;
        
        for(int i=0; i<n-1; i++)
        {
            if(position[i+1]-position[i] > distance) narr.push_back(speed[i]);
        }
        narr.push_back(speed[n-1]);

        
        int m = narr.size();
        int mini = narr[m-1];
        int ans = 0;
        
        for(int i=m-1; i>=0; i--)
        {
            if(mini >= narr[i])
            {
                mini = narr[i];
                ans++;
            }
            else narr[i] = mini;
        }
        return ans;      
    }
};