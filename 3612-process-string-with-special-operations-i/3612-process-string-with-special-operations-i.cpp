class Solution {
public:
    string processStr(string s) {
        string ans;

        for(char c:s) 
        {
            if(c == '*') // remove last character
            {
                if(ans.length()) ans.pop_back();
            }
            else if(c == '#') // append itself
            {
                ans.append(ans);
            }
            else if(c == '%') // reverse current
            {
                reverse(ans.begin(), ans.end());
            }
            else // character is a letter
            {
                ans.push_back(c);
            }
        }

        return ans;
    }
};