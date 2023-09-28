class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = nums[0];
        int res = curMax;
        int n = nums.size();
        for(int i=1; i<n; i++){
            curMax = max(curMax+nums[i], nums[i]);
            res = max(res, curMax);
        }
        
        return res;
    }
};