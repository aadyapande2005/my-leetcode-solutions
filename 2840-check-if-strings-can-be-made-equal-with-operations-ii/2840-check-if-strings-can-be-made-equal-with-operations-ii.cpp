class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        // cout<<n<<endl;
        vector<int> freq1(26);
        vector<int> freq2(26);

        for(int i=0; i<n; i+=2)
        {
            char cs11 = s1[i];
            char cs21 = s2[i];
            
            // cout<<cs21<<" ";
            // cout<<cs11<<" ";

            freq1[cs11-'a']++;
            freq1[cs21-'a']--;

            if(i+1 < n)
            {
                char cs12 = s1[i+1];
                char cs22 = s2[i+1];

                // cout<<cs12<<" ";
                // cout<<cs22<<" ";
                // cout<<endl;

                freq2[cs12-'a']++;
                freq2[cs22-'a']--;
            } 
        }

        for(int i=0; i<26; i++)
        {
            if(freq1[i] != 0 || freq2[i] != 0) 
                return false;
        }

        return true;
    }
};