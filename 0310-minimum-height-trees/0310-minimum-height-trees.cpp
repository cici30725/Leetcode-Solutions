class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        
        queue<int> leaves;
        for(int i=0; i<n; i++){
            if(deg[i]==1)
                leaves.push(i);
        }
        
        while(n>2){
            n-=leaves.size();
            int q_size = leaves.size();
            for(int i=0; i<q_size; i++){
                int u = leaves.front();
                leaves.pop();
                for(int v : adj[u]){
                    deg[v]--;
                    if(deg[v]==1)
                        leaves.push(v);
                }
            }
        }
        
        vector<int> sol;
        while(!leaves.empty()){
            sol.push_back(leaves.front());
            leaves.pop();
        }
        
        return sol;
    }
};