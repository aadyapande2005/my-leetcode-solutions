class Solution {
public:    
    string kthLargestNumber(vector<string>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
                
        auto cmp = [](string&a, string&b)
        {
            if(a.size() != b.size()) return a.size() > b.size();
            else return a > b;
        };

        priority_queue<string, vector<string>, decltype(cmp)> pq;

        

        for(string s:nums)
        {
            pq.push(s);

            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};