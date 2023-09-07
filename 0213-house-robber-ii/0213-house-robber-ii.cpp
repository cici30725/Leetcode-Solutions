class Solution {
public:
    int robber(vector<int>& nums, int start, int end){
        int cur = 0;
        int prev = 0;
        
        for(int i=start; i<=end; i++){
            int next = max(prev + nums[i], cur);
            prev = cur;
            cur = next;
        }
        
        return cur;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int rob1 = robber(nums, 0, nums.size()-2);
        int rob2 = robber(nums, 1, nums.size()-1);
        
        return max(rob1, rob2);
    }
};