class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower_idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lower_idx == nums.size() || nums[lower_idx]!=target)
            return {-1, -1};
        int h_idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {lower_idx, h_idx-1};
    }
};