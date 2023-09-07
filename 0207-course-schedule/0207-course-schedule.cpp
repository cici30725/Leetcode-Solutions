class Solution {
public:
    bool dfs(int cur, unordered_map<int, vector<int>>& m, unordered_set<int>& visited){
        if(visited.find(cur)!=visited.end())
            return false;
        
        visited.insert(cur);
        for(int v : m[cur]){
            if(!dfs(v, m, visited))
                return false;
        }
        
        m[cur].clear();
        visited.erase(cur);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        for(auto& v : prerequisites) {
            m[v[1]].push_back(v[0]);
        }
        
        unordered_set<int> visited;
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, m, visited))
                return false;
        }
        return true;
    }
};