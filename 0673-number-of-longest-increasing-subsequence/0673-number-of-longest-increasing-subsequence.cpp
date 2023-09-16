class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n);
        dp[0] = {1, 1};
        int max_num_path = 1;
        int max_len = 1;
        for(int i=1; i<n; i++){
            int cur_len = 1, num_path = 1;
            for(int j=0; j<i; j++){
                if(nums[j] >= nums[i])
                    continue;
                
                if(dp[j].first + 1 > cur_len){
                    cur_len = dp[j].first + 1;
                    num_path = dp[j].second;
                }
                else if(dp[j].first + 1 == cur_len){
                    num_path += dp[j].second;
                }
            }
            dp[i] = {cur_len, num_path};
            if(cur_len > max_len){
                max_len = cur_len;
                max_num_path = num_path;
            }
            else if(cur_len == max_len)
                max_num_path += num_path;
        }
        
        return max_num_path;
    }
};