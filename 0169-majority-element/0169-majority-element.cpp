class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> um;
        for(int i : nums){
            um[i]++;
            if(um[i] > n/2)
                return i;
        }
        
        return -1;
    }
};