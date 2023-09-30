class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 !=0)
            return false;
        total /= 2;
        
        int n = nums.size();
        vector<vector<bool>> dp(total+1, vector<bool>(n+1, false));
        
        for(int i=0; i<=n; i++)
            dp[0][i] = true;
        
        for(int i=1; i<=total; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = dp[i][j-1];
                if(i>=nums[j-1])
                    dp[i][j] = dp[i][j] | dp[i-nums[j-1]][j-1];
            }
        }
        
        return dp[total][n];
    }
};