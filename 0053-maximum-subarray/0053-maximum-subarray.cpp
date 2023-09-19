class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -INT_MAX;
        int cur_sum=0;
        int cur_min=0;
        for(int i=0; i<nums.size(); i++){
            cur_sum+=nums[i];
            res = max(res, cur_sum - cur_min);
            cur_min = min(cur_min, cur_sum);
        }
        return res;
    }
};