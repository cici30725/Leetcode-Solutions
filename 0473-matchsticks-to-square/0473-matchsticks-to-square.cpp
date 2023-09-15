class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total % 4 !=0)
            return false;
        
        total /= 4;
        
        unordered_map<int, bool> memo;
        function<bool(int, int)> dfs = [&](int i, int cur_sum) ->bool{
            if(i==0)
                return true;
            
            if(memo.count(i))
                return memo[i];
            
            for(int j=0; j<matchsticks.size(); j++){
                if(!((1<<j) & i))
                    continue;
                i = i ^ (1<<j);
                if(cur_sum + matchsticks[j] <= total && dfs(i, (cur_sum + matchsticks[j])%total)){
                    return true;
                }
                i = i ^ (1<<j);
            }
            
            return memo[i] = false;
        };
        
        return dfs((1 << matchsticks.size())-1, 0);
    }
};