class Solution {
public:
    void bfs(int root, vector<vector<int>>& adj, vector<int>& d){
        queue<int> q;
        q.push(root);
        d[root] = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int v : adj[u]){
                if(d[v]==-1){
                    d[v] = d[u]+1;
                    q.push(v);
                }
            }
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        }
        
        vector<int> n1_d(n, -1);
        vector<int> n2_d(n, -1);
        bfs(node1, adj, n1_d);
        bfs(node2, adj, n2_d);
        
        int res = INT_MAX;
        int idx = -1;
        for(int i=0; i<n; i++){
            // cout<<i<<" "<<n1_d[i]<<" "<<n2_d[i]<<endl;
            if(n1_d[i]!=-1 && n2_d[i]!=-1){
                if(res > max(n1_d[i], n2_d[i])){
                    res = max(n1_d[i], n2_d[i]);
                    idx = i;
                }
            }
        }
        return idx;
    }
};