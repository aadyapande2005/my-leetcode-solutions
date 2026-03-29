class Solution {
public:
    int numDifferentIntegers(string word) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = word.size();
        unordered_set<string> st;

        for(int i=0; i<n; i++)
        {
            string s;
            while(i<n && word[i] >= '0' && word[i] <= '9')
            {
                s.push_back(word[i]);
                i++;
            }
            if(s.length() != 0)
            {
                int j = 0;
                while(s[j] == '0') j++;
                if(j != 0) s = s.substr(j);
                st.insert(s);
                i--;
            }
        }

        return st.size();
    }
};