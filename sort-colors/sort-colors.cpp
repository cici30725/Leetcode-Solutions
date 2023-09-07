class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = -1, r = nums.size();
        int i = 0;
        while(i<r){
            if(nums[i]==0){
                l++;
                swap(nums[i], nums[l]);
                i++;
            }
            else if(nums[i]==2){
                r--;
                swap(nums[i], nums[r]);
            }
            else
                i++;
        }
    }
};