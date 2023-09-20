class Solution {
public:
    using ll = long long;
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        ll curSum = nums[0];
        ll res = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] > res)
                res = max((curSum+nums[i])/(i+1) + ((curSum+nums[i])%(i+1) ? 1 : 0), res);
            curSum+=nums[i];
        }
        
        return res;
    }
};