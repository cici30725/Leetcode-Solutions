class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<unsigned int> dp(target+1, 0);
    dp[0] = 1;
    for(int total=1; total<=target; total++) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= total) dp[total] += dp[total - nums[i]];
            else break;
        }
    }
    return dp[target];
    }
};