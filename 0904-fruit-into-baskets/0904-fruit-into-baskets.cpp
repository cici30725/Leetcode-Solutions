class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> M;
        int cur = 0;
        int sol = 0;
        for(int i=0; i<fruits.size(); i++){
            M[fruits[i]] = i;
            if(M.size()>2){
                int out;
                for(auto& [type, _] : M){
                    if(type!=fruits[i] && type!=fruits[i-1]){
                        out = type;
                        break;
                    }
                }
                cur = i - M[out];
                M.erase(out);
            }
            else
                cur++;
            sol = max(sol, cur);
        }
        return sol;
    }
};