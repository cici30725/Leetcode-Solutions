class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev_min = nums[0];
        int prev_max = nums[0];
        int best = nums[0];
        for(int j = 1; j<nums.size(); j++){
            int i = nums[j];
            int cur_min = min(prev_min * i, min(prev_max * i, i));
            int cur_max = max(prev_max * i, max(prev_min * i, i));
            // cout<<cur_min<<" "<<cur_max<<endl;
            best = max(best, cur_max);
            prev_max = cur_max;
            prev_min = cur_min;
        }
        return best;
    }
};