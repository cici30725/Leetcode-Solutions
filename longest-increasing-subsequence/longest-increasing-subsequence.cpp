class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;
        int sol = 1;
        for(int i=1; i<nums.size(); i++){
            int best = 0;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i])
                    best = max(best, dp[j]);
            }
            dp[i] = best + 1;
            sol = max(dp[i], sol);
        }
        return sol;
    }
};