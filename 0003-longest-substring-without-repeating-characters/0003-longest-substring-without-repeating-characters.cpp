class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        unordered_map<char, int> M;
        int l = 0, r = 1;
        M[s[l]] = 1;
        int best = 1;
        while(r<s.size()){
            M[s[r]]++;
            while(M[s[r]]>1){
                M[s[l]]--;
                l++;
            }
            best = max(best, r-l+1);
            r++;
        }
        return best;
    }
};