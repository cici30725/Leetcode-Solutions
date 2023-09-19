class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = -1, r = removable.size()+1;
        unordered_set<int> S;
        
        auto check = [&](int cur_max) -> bool {
            int cur = 0;
            for(int i=0; i<s.length(); i++){
                if(S.find(i)!=S.end())
                    continue;
                if(cur < p.length() && p[cur] == s[i])
                    cur++;
                else if(cur==p.length())
                    break;
            }
            
            return cur==p.length();
        };
        
        int prev_m = 0;
        
        while(r-l>1){
            int m = (l+r)/2;
            if(m>prev_m){
                for(int i=prev_m+1; i<=m; i++)
                    S.insert(removable[i-1]);
            }
            else{
                for(int i=prev_m; i>m; i--)
                    S.erase(removable[i-1]);
            }
            
            if(check(m)){
                l = m;
            }
            else{
                r = m;
            }
            prev_m = m;
        }
        
        return l;
    }
};