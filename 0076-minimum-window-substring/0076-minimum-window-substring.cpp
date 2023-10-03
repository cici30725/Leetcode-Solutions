class Solution {
public:
    int to_idx(char c){
        return c>='A' && c<='Z' ? c-'A'+26 : c-'a';
    }
    
    bool match(array<int, 52>& freq, array<int, 52>& window){
        for(int i=0; i<52; i++){
            if(window[i] < freq[i])
                return false;
        }
        
        return true;
    }
    
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        
        array<int, 52> freq{};
        array<int, 52> window{};
        for(char c : t){
            freq[to_idx(c)]++;
        }
        
        int l = -1, r = 0;
        pair<int, int> res = {-1, s.size()};
        for(; r<s.size(); r++){
            window[to_idx(s[r])]++;
            while(l<r && match(freq, window)){
                if(r-l < res.second-res.first){
                    res = {l, r};
                }
                l++;
                window[to_idx(s[l])]--;
            }
        }
        
        if(res.second == s.size())
            return "";
        else
            return s.substr(res.first+1, res.second-res.first);
    }
};