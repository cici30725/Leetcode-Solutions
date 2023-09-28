class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um; // <value, index>
        int n = nums.size();
        int idx1, idx2;
        for(int i=0; i<n; i++){
            int cur = nums[i];
            if(um.find(target-cur)!=um.end()){
                idx1 = i;
                idx2 = um[target-cur];
                break;
            }
            um[cur] = i;
        }
        
        return {idx1, idx2};
    }
};