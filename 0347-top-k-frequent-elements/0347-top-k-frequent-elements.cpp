class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i : nums)
            freq[i]++;
        
        vector<vector<int>> bucket(n+1);
        for(auto& [k, v] : freq){
            bucket[v].push_back(k);
        }
        
        vector<int> sol;
        for(int i=n; i>=1; i--){
            if(sol.size()>=k)
                break;
            sol.insert(sol.end(), bucket[i].begin(), bucket[i].end());
        }
        return sol;
        
    }
};