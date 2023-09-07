class Solution {
public:
    void dfs(vector<vector<int>>& sol, int cur, vector<int>& nums) {
        if(cur == nums.size()){
            sol.push_back(nums);
            return;
        }
        for(int i=cur; i<nums.size(); i++){
            swap(nums[i], nums[cur]);
            dfs(sol, cur+1, nums);
            swap(nums[i], nums[cur]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        dfs(sol, 0, nums);
        return sol;
    }
};