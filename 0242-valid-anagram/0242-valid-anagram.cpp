class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        array<int, 26> freq_s{}, freq_t{};
        for(int i=0; i<s.size(); i++){
            freq_s[s[i]-'a']++;
            freq_t[t[i]-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(freq_s[i]!=freq_t[i]){
                return false;
            }
        }
        return true;
    }
};