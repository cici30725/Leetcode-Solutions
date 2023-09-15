class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> uniq_nums;
        unordered_map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){
                freq[nums[i]]++;
            }
            else{
                freq[nums[i]]=1;
                uniq_nums.push_back(nums[i]);
            }
        }
        
        int n = uniq_nums.size();
        vector<int> dp(n, 0);
        dp[0] = freq[uniq_nums[0]] * uniq_nums[0];
        if(n==1)
            return dp[0];
        dp[1] = uniq_nums[1]-uniq_nums[0]==1 ? max(dp[0], uniq_nums[1]*freq[uniq_nums[1]]) : dp[0] + uniq_nums[1]*freq[uniq_nums[1]];
        
        for(int i=2; i<n; i++){
            int cur_val = uniq_nums[i];
            int cur_cnt = freq[cur_val];
            int prev_val = uniq_nums[i-1];
            if(cur_val - prev_val > 1)
                dp[i] = dp[i-1] + cur_val * cur_cnt;
            else{
                dp[i] = max(dp[i-1], dp[i-2] + cur_val * cur_cnt);
            }
        }
        
        return dp[n-1];
        
    }
};