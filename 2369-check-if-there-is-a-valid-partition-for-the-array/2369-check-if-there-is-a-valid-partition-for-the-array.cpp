class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> dp(n+1, false);
        dp[0] = true;
        dp[1] = false;
        dp[2] = nums[0]==nums[1];
        
        for(int i=2; i<n; i++){
            if(nums[i] == nums[i-1])
                dp[i+1] = dp[i+1] || dp[i-1];
            if(nums[i] == nums[i-1] && nums[i-1] == nums[i-2])
                dp[i+1] = dp[i+1] || dp[i-2];
            if(nums[i]-nums[i-1]==1 && nums[i-1]-nums[i-2]==1)
                dp[i+1] = dp[i+1] || dp[i-2];
        }
        
        return dp[n];
    }
};