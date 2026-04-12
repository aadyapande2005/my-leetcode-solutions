class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        map<int, int> dp;
        dp[0] = 0;

        for (int r : rods) {
            map<int, int> new_dp(dp);

            for (auto entry : dp) {
                int diff = entry.first;
                int taller = entry.second;
                int shorter = taller - diff;

                int new_taller =
                    new_dp.count(diff + r) > 0 ? new_dp[diff + r] : 0;
                new_dp[diff + r] = max(new_taller, taller + r);

                int new_diff = abs(shorter + r - taller);
                int new_taller2 = max(shorter + r, taller);
                new_dp[new_diff] =
                    max(new_taller2,
                        new_dp.count(new_diff) > 0 ? new_dp[new_diff] : 0);
            }

            dp = new_dp;
        }

        return dp.count(0) > 0 ? dp[0] : 0;
    }
};