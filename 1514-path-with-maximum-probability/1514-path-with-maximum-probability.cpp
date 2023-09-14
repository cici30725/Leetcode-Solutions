class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        using pp = pair<double, int>;
        vector<double> d(n, -1);
        vector<vector<pp>> adj(n);
        for(int i=0; i<edges.size(); i++){
            double w = succProb[i];
            int u = edges[i][0], v = edges[i][1];
            adj[u].emplace_back(w, v);
            adj[v].emplace_back(w, u);
        }
        
        double sol = 0;
        priority_queue<pp, vector<pp>, greater<pp>> q;
        q.push({0, start_node});
        while(q.size()){
            pp cur = q.top();
            q.pop();
            int u = cur.second;
            double w = cur.first;
            
            if(d[u]>=0)
                continue;
            
            d[u] = w;
            cout<<u<<" "<<w<<endl;
            if(u==end_node){
                sol = exp(-w);
                break;
            }
            for(auto& next : adj[u]){
                int v = next.second;
                double next_w = -log(next.first);
                // cout<<"next "<<v<<" "<<next.second<<" "<<next_w<<endl;
                if(d[v]==-1 || d[u] + next_w < d[v]){
                    q.push({d[u]+next_w, v});
                }
            }
        }
        
        return sol;
    }
};