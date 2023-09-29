class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0, l = 0;
        int n = s.size();
        unordered_set<char> letters;
        int res = 0;
        while(r < n){
            char cur_chat = s[r];
            while(letters.find(cur_chat)!=letters.end()){
                letters.erase(s[l]);
                l++;
            }
            letters.insert(cur_chat);
            res = max(res, r-l+1);
            r++;
        }
        
        return res;
    }
};