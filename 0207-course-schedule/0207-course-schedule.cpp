class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto& v : prerequisites){
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        int nodes_visited = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            nodes_visited++;
            for(int v : adj[cur]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        
        return nodes_visited == n;
    }
};