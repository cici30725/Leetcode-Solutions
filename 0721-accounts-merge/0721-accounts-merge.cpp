class Solution {
public:
    struct DSU{
        int m_n; 
        vector<int> who;
        vector<int> rank;
        
        DSU(int n): m_n{n} {
            who.resize(n);
            rank.resize(n);
            
            for(int i=0; i<m_n; i++){
                who[i] = i;
                rank[i] = 0;
            }
        };
        
        void join(int a, int b){
            int p_a = find(a), p_b = find(b);
            if(rank[p_a] > rank[p_b])
                swap(p_a, p_b);
            
            if(rank[p_a] < rank[p_b])
                who[p_a] = p_b;
            else{
                who[p_a] = p_b;
                rank[p_b]++;
            }
        }
        
        int find(int a){
            if(who[a]!=a)
                return who[a] = find(who[a]);
            else
                return a;
        }
    };
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        unordered_map<string, vector<int>> um;
        
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                um[accounts[i][j]].push_back(i);
            }
        }
        
        DSU dsu{n};
        
        for(auto& [_, idx_vec] : um){
            for(int i=1; i<idx_vec.size(); i++){
                dsu.join(idx_vec[i-1], idx_vec[i]);
            }
        }
        
        unordered_map<int, set<string>> group_to_string;
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                group_to_string[dsu.find(i)].insert(accounts[i][j]);
                // cout<<dsu.find(i)<<" "<<accounts[i][j]<<endl;
            }
        }
        
        vector<vector<string>> sol;
        for(auto& [groupId, emails] : group_to_string){
            vector<string> cur{accounts[groupId][0]};
            for(auto& email : emails)
                cur.push_back(email);
            sol.push_back(cur);
        }
        
        return sol;
    }
};