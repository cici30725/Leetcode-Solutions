class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_arr(n);
        vector<int> max_arr(n);
        for(int i=0; i<n; i++){
            if(i==0)
                min_arr[i] = nums[i];
            else
                min_arr[i] = min(min_arr[i-1], nums[i]);
        }
        
        for(int i=n-1; i>=0; i--){
            if(i==n-1)
                max_arr[i] = nums[i];
            else
                max_arr[i] = max(max_arr[i+1], nums[i]);
        }
        
        for(int i=1; i<n-1; i++){
            if(nums[i] > min_arr[i-1] && nums[i] < max_arr[i+1])
                return true;
        }
        return false;
    }
};