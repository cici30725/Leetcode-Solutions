class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(r-l>1){
            int m = (l+r)/2;
            if(nums[l]>=nums[r] && nums[m]>=nums[l]){
                if(target>=nums[l] && target<=nums[m])
                    r = m;
                else
                    l = m;
            }
            else if(nums[l]>=nums[r] && nums[m]<nums[l]){
                if(target>=nums[m] && target <= nums[r])
                    l = m;
                else
                    r = m;
            }
            else{
                if(target>=nums[m])
                    l = m;
                else
                    r = m; 
            }
        }
        
        if(nums[l]==target)
            return l;
        else if(nums[r]==target)
            return r;
        else
            return -1;
    }
};