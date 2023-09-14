class Solution {
public:
    // unordered_set<string, int> out;
    unordered_map<string, vector<string>> adj;
    vector<string> sol;
    
    void dfs(const string& cur){
        while(!adj[cur].empty()){
            string s = adj[cur].back();
            adj[cur].pop_back();
            dfs(s);
        }
        
        sol.push_back(cur);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& e : tickets){
            const string& u = e[0];
            const string& v = e[1];
            adj[u].push_back(v);
        }
        
        for(auto& [_, v] : adj){
            sort(v.begin(), v.end(), greater<string>());
        }
        
        dfs("JFK");
        
        reverse(sol.begin(), sol.end());
        return sol;
    }
};