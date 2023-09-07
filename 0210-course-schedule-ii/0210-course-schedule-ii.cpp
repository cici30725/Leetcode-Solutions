class Solution {
public:
    bool dfs(int cur, unordered_map<int, vector<int>>& m, unordered_set<int>& cycle, unordered_set<int>& visit, vector<int>& sol){
        if(cycle.find(cur)!=cycle.end())
            return false;
        if(visit.find(cur)!=visit.end())
            return true;
        
        cycle.insert(cur);
        for(int v : m[cur]){
            if(!dfs(v, m, cycle, visit, sol))
                return false;
        }
        
        m[cur].clear();
        cycle.erase(cur);
        visit.insert(cur);
        sol.push_back(cur);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        for(auto& v : prerequisites) {
            m[v[1]].push_back(v[0]);
        }
        
        unordered_set<int> cycle;
        unordered_set<int> visit;
        vector<int> sol;
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, m, cycle, visit, sol))
                return {};
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};