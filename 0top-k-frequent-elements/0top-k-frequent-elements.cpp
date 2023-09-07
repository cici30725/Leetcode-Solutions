class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i : nums){
            freq[i]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto& [k, v] : freq){
            bucket[v].push_back(k);
        }
        vector<int> sol;
        for(int i=bucket.size()-1; i>=1; i--){
            if(sol.size()==k)
                break;
            sol.insert(sol.end(), bucket[i].begin(), bucket[i].end());
        }
        return sol;
    }
};