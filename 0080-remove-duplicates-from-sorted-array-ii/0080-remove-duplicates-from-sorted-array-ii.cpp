class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        int cnt = 1;
        while(l<r){
            if(nums[l]==nums[l-1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            
            if(cnt>2){
                int cur = nums[l];
                nums.erase(nums.begin()+l);
                nums.push_back(cur);
                r--;
            }
            else{
                l++;
            }
        }
        
        return l;
    }
};