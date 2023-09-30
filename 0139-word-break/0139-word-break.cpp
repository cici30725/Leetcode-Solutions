class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++){
            for(string& word : wordDict){
                if(i<word.size())
                    continue;
                if(s.compare(i-word.size(), word.size(), word) == 0)
                    dp[i] = dp[i] | dp[i-word.size()];
            }
        }
        
        return dp[n];
    }
};