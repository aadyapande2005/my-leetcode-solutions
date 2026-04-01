class Solution {
public:    
    long long countSubstrings(string s, char c) {
        long long n = 0;

        for(char t:s) 
            if(t == c) n++;

        return n*(n+1)/2;
    }
};