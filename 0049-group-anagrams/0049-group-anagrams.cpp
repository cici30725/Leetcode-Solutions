class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> M;
        vector<vector<string>> sol;
        int cur_idx = 0;
        
        for(string s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if(M.find(tmp)==M.end()){
                M[tmp] = cur_idx++;
                sol.push_back({s});
            }
            else{
                int idx = M[tmp];
                sol[idx].push_back(s);
            }
        }
        
        return sol;
    }
};