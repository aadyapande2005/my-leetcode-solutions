class Solution {
public:
    int mirrorDistance(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        string temp = to_string(n);
        reverse(temp.begin(), temp.end());
        return abs(stoi(temp) - n);
    }
};