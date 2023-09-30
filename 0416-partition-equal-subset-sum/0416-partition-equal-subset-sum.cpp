class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 !=0)
            return false;
        total /= 2;
        
        int n = nums.size();
        vector<bool> dp(total+1, false);
        
        dp[0] = true;
        
        for(int j=1; j<=n; j++){
            for(int i=total; i>=1; i--){
                if(i>=nums[j-1])
                    dp[i] = dp[i] | dp[i-nums[j-1]];
            }
        }
        
        /*
        for(int i=1; i<=total; i++){
            for(int j=n; j>=1; j--){
                if(i>=nums[j-1])
                    dp[i] = dp[i] | dp[i-nums[j-1]];
            }
        }
        */
        
        return dp[total];
    }
};