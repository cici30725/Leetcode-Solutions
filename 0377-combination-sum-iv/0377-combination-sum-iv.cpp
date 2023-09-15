class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned> dp(target+1, 0);
        dp[0] = 1;
        for(int cur = 1; cur<=target; cur++){
            for(int i : nums){
                if(cur>=i) dp[cur] += dp[cur-i];
                else break;
            }
        }
        
        return dp[target];
    }
};