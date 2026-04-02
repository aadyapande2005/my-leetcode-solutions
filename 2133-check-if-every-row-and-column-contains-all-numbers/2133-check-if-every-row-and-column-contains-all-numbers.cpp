class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int> st1;
        unordered_set<int> st2;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                st1.insert(matrix[i][j]);
                st2.insert(matrix[j][i]);
            }
            if(st1.size() != n) return false;
            if(st2.size() != n) return false;
            st1.clear();
            st2.clear();
        }

        return true;
    }
};