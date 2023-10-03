class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> freq{};
        int cnt = 0;
        for(char c : t){
            freq[c]++;
            if(freq[c]==1)
                cnt++;
        }
        
        int res_l;
        int res_len = INT_MAX;
        int l = -1, r = 0;
        while(r<s.size()){
            freq[s[r]]--;
            
            if(freq[s[r]] == 0)
                cnt--;
            
            if(cnt==0){
                // cout<<l<<" "<<r<<endl;
                
                while(cnt==0){
                    if(r-l < res_len){
                        res_len = r-l;
                        res_l = l+1;
                    }
                    
                    l++;
                    freq[s[l]]++;
                    if(freq[s[l]]>0)
                        cnt++;
                }
            }
            
            r++;
        }
        
        if(res_len == INT_MAX)
            return "";
        else
            return s.substr(res_l, res_len);
        
    }
};