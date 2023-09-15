class Solution {
public:
    int maxLength(vector<string>& arr) {
        array<int, 26> freq{};
        int res = 0;
        
        function<void(int, int)> dfs = [&](int idx, int cur_len) {
            if(idx==arr.size()){
                res = max(cur_len, res);
                return;
            }
            
            dfs(idx+1, cur_len);
            
            bool flag = false;
            for(char c : arr[idx]){
                if(freq[c-'a']>0){
                    flag = true;
                }
                freq[c-'a']++;
            }
            
            if(!flag)
                dfs(idx+1, cur_len+arr[idx].size());
            for(char c : arr[idx]) freq[c-'a']--;
        };
        
        dfs(0, 0);
        return res;
    }
};