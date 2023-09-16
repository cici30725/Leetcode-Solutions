class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(), N = 1<<n;
        vector<uint> dp(N, -1);
        dp[0] = 0;
        for(int i=0; i<N; i++) {
            if(dp[i]==-1)
                continue;
            for(string& s : stickers){
                int sup = i;
                for(char c : s) {
                    for(int j=0; j<n; j++){
                        if(c == target[j] && !((sup>>j) & 1)){
                            sup = sup | (1 << j);
                            break;
                        }
                    }
                }
                
                dp[sup] = min(dp[sup], dp[i]+1);
            }
        }
        
        return dp[N-1];
    }
};