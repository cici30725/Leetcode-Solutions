class Solution {
public:
    bool dfs(int cur, vector<vector<int>>& adj, unordered_set<int>& visit){
        if(visit.find(cur)!=visit.end())
            return true;
        
        visit.insert(cur);
        for(int v : adj[cur]){
            if(dfs(v, adj, visit))
                return true;
        }
        
        visit.erase(cur);
        adj[cur].clear();
        return false;
    }
        
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visit;
        for(int i=0; i<n; i++){
            if(dfs(i, adj, visit))
                return false;
        }
        
        return true;
    }
};