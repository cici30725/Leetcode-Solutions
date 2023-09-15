class Solution {
public:
    bool splitString(string s) {
        using ll = unsigned long long;
        
        function<bool(int, ll, ll, int)> dfs;
        dfs = [&](int idx, ll cur_sum, ll prev_num, int splits) -> bool {
            if(idx >= s.size()){
                if(splits>=2)
                    return true;
                else
                    return false;
            }
            
            for(int i=idx; i<s.size(); i++){
                // if(i-idx+1>s.size()/2)
                    // break;
                char c = s[i];
                cur_sum = cur_sum*10 + (c-'0');
                // int new_sum = cur_sum + (c-'0');
                // cout<<idx<<" "<<i<<" "<<prev_num<<" "<<cur_sum<<endl;
                if(idx>0 && cur_sum>=prev_num)
                    break;
                if(idx>0 && prev_num-cur_sum!=1 )
                    continue;
                if(dfs(i+1, 0, cur_sum, splits+1))
                    return true;
            }
            return false;
        };
        
        return dfs(0, 0, 0, 0);
    }
};