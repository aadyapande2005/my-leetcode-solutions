class Solution {
public:
    int rev(int n)
    {
        /*
            n = 2541
            2541/10 = 254
            2541%10 = 1

            254/10 = 25
            254%10 = 4

            25/10 = 2
            25%10 = 5

            2/10 = 0
            2%10 = 2

            stack = 2 5 4 1

            2 + 50 + 400 + 1000
        */
        stack<int> st;

        while(n > 0)
        {
            int num = n/10;
            int rem = n%10;

            st.push(rem);
            n = num;
        }

        int pw = st.size();

        int rev_num = 0;

        for(int i=0; i<pw; i++)
        {
            rev_num += st.top()*pow(10,i);
            st.pop();
        }

        return rev_num;        
    }
    int mirrorDistance(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int rev_num = rev(n);
        return abs(rev_num - n);
    }
};