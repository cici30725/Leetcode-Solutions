class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        for(int i : nums){
            M[i]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto& [key, val] : M){
            pq.push({val, key});
        }
        
        vector<int> sol;
        for(int i=0; i<k; i++){
            sol.push_back(pq.top().second);
            pq.pop();
        }
        return sol;
    }
};