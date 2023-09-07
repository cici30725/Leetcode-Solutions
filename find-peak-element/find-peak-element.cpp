class Solution {
public:
    int find(int l, int r, vector<int>& nums){
        if(l==r)
            return l;
        if(r-l==1)
            return nums[r] > nums[l] ? r : l;
        
        int m = (l+r)/2;
        if(nums[m+1]>=nums[m])
            return find(m+1, r, nums);
        else
            return find(l, m, nums);
    }
    int findPeakElement(vector<int>& nums) {
        return find(0, nums.size()-1, nums);
    }
};