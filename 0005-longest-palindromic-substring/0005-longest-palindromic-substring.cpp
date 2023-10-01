class Solution {
public:
    pair<int, int> test(int l, int r, string& s){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        
        return {l+1, r-1};
    }
    
    string longestPalindrome(string s) {
        auto bestPair = make_pair(0, 0);
        for(int i=0; i<s.size(); i++){
            auto oddPair = test(i, i, s);
            if(oddPair.second - oddPair.first > bestPair.second - bestPair.first)
                bestPair = oddPair;
            // res = max(res, test(i, i, s));
            if(i<s.size()-1){
                // res = max(res, test(i, i+1, s));
                auto evenPair = test(i, i+1, s);
                if(evenPair.second - evenPair.first > bestPair.second - bestPair.first)
                    bestPair = evenPair;
            }
        }
        
        return s.substr(bestPair.first, (bestPair.second - bestPair.first + 1));
    }
};